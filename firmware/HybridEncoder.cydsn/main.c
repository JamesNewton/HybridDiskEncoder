/* 
Hybrid Encoder Firmware

Ver 0.1 Connect via serial terminal 115,200 N81, 
 - 's' shows sin, cos, and ATAN2
 - '8' sin LED drive up '2' sin LED drive down
 - '6' cos LED drive up '4' cos LED drive down

TODO: Setup a timer and just output ATAN2 regularly
*/
#include <project.h>
#include <stdio.h>

#define CH0         (0x00u)
#define CH1         (0x01u)
#define CH2_SIN     (0x02u)
#define CH3_COS     (0x03u)

#define LED_MAX (int)PWM_2_PERIOD_REG

#define BRAD_PI_SHIFT 14
#define BRAD_PI  (1<<BRAD_PI_SHIFT)
static const uint BRAD_HPI= BRAD_PI/2;
static const uint BRAD_2PI= BRAD_PI*2; 

static const uint ATAN_ONE = 0x1000, ATAN_FP= 12;

volatile uint32 dataReady = 0u;
volatile int16 result[ADC_TOTAL_CHANNELS_NUM];

#define OCTANTIFY(_x, _y, _o)   do {                            \
    int _t; _o= 0;                                              \
    if(_y<  0)  {            _x= -_x;   _y= -_y; _o += 4; }     \
    if(_x<= 0)  { _t= _x;    _x=  _y;   _y= -_t; _o += 2; }     \
    if(_x<=_y)  { _t= _y-_x; _x= _x+_y; _y=  _t; _o += 1; }     \
} while(0);

CY_ISR(ISR_TIMER_LOC) { //heartbeat. Keep for timed response?
    //UART_UartPutChar(result[0]&0xFF);
    UART_UartPutChar('.'); //blip
    UART_UartPutChar(8); //backspace over the blip
    }

CY_ISR(ADC_ISR_LOC) {
    uint32 intr_status;
    uint32 range_status;

    intr_status = ADC_SAR_INTR_MASKED_REG; //read int status reg
    if((intr_status & ADC_EOS_MASK) != 0u) { //End of scan?
        range_status = ADC_SAR_RANGE_INTR_MASKED_REG; //range status
        /* Keep this for autoranging in the future
        if((range_status & (uint32)(1ul << CH0_SIN)) != 0u) {
            result[CH0_SIN] = ADC_GetResult16(CH0_SIN); //Get result
            // Set PWM compare from channel so LED glows as vin rises
            PWM_WriteCompare(result[CH0_SIN]); 
            }    
        */
        // Clear range detect status ??? Why does this clear it?
        ADC_SAR_RANGE_INTR_REG = range_status;
        result[CH2_SIN] = ADC_GetResult16(CH2_SIN); //Get result
        //shouldn't need to check for completion for CH1, locked to CH0, right?
        result[CH3_COS] = ADC_GetResult16(CH3_COS); //Get cos result
        dataReady |= ADC_EOS_MASK;
        }

    ADC_SAR_INTR_REG = intr_status; //clear handled interrupt
    }

// QDIV stands for the fixed-point division method most appropriate for 
// your system. Modify where appropriate.
// This would be for NDS.
static inline int QDIV(int num, int den, const int bits) {
    int bignum;
    bignum = num;
    bignum <<= bits;
    bignum /= den;
    return (int)bignum;
    }

// Approximate Taylor series for atan2, home-grown implementation. 
// Returns [0,2pi), where pi ~ 0x4000.
uint atan2Tonc(int x, int y) {
    if(y==0)    return (x>=0 ? 0 : BRAD_PI);

    static const int fixShift= 15;
    int  phi, t, t2, dphi;

    OCTANTIFY(x, y, phi);
    phi *= BRAD_PI/4;

    t= QDIV(y, x, fixShift);
    t2= -t*t>>fixShift;

    dphi= 0x0470;
    dphi= 0x1029 + (t2*dphi>>fixShift);
    dphi= 0x1F0B + (t2*dphi>>fixShift);
    dphi= 0x364C + (t2*dphi>>fixShift);
    dphi= 0xA2FC + (t2*dphi>>fixShift);
    dphi= dphi*t>>fixShift;

    return phi + ((dphi+4)>>3);
    }


int main() {
    char ch;
    char  uartLine[250];
    int sin, cos;
    int center_sin = 500;
    int center_cos = 200;
    int led_sin = 0;
    int led_cos = 0;
    
    UART_Start(); //Start the UART
    UART_UartPutString("\0x0COk\r\n"); //Hello world!

    ADC_Start(); //Init ADC
    ADC_StartConvert(); //Start ADC sequencing
    ADC_IRQ_StartEx(ADC_ISR_LOC); //for ADC
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_2_Start();
    
    for(;;) {
        ch = UART_UartGetChar(); //non-blocking. Zero if RX FIFO empty
        if(0u != ch) {
            UART_UartPutChar(ch); //blocking, will wait for TX FIFO empty.
            if ('s' == ch) { 
                sin = result[CH2_SIN] - center_sin;
                cos = result[CH3_COS] - center_cos;
                sprintf(uartLine, " %d,%d = %d\r\n" 
                    ,sin
                    ,cos
                    ,atan2Tonc(sin,cos)/91
                    );
                UART_UartPutString(uartLine); //blocking
                }
            if ('2' == ch) { 
                led_sin--;
                if (led_sin < 0) led_sin = 0;
                }
            if ('8' == ch) { 
                led_sin++;
                if (led_sin > LED_MAX) led_sin = LED_MAX;
                }
            if ('4' == ch) { 
                led_cos--;
                if (led_cos < 0) led_cos = 0;
                }
            if ('6' == ch) { 
                led_cos++;
                if (led_cos > LED_MAX) led_cos = LED_MAX;
                }
            PWM_1_WriteCompare(led_cos);
            PWM_2_WriteCompare(led_sin);
            }
        }
    }
