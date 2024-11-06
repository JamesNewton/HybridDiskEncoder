
#include <math.h>
#define BAUD 115200
//pin assignments
#define SIN_LED 16
#define COS_LED 17
#define SIN_ADC 26
#define COS_ADC 27

char c; //input characters
int32_t n; //accumulator for numbers
int32_t sincenter, coscenter; //center point on ADC scale for sine and cosine 

//encoder state
int8_t old_state = 0;

// Current count, position, goal and drive (positive or negative)
int32_t count = 0;
int32_t position = 0;
int32_t goal = 500;
int32_t drive = 0;

// Quadrature Encoder Matrix
// Indexed by the bits AoBoAnBn 
//Where A and B are the encoder outputs and o and n are old and new. 
//e.g. Ao is the OLD value of A. See the read_encoder function below.
//  0 = nop: no change
//  1 = inc: increment (positive rotation)
// -1 = dec: decrement (negative rotation)
//  2 = err: error (both changed, so we missed a state)
int QEM [16] = { //C++ doesn't need everything on one line, so lets break it up:
//old new:0  1  2  3 //
/*0=00*/  0,-1, 1, 2,// 0->0? nop, 1->0? dec, 2->0? inc, 3->0? err
/*1=01*/  1, 0, 2,-1,// 0->1? inc, 1->1? nop, 2->1? err, 3->1? dec
/*2=02*/ -1, 2, 0, 1,// 0->2? dec, 1->2? err, 2->2? nop, 3->2? inc
/*3=03*/  2, 1,-1, 0 // 0->3? err, 1->3? inc, 2->3? dec, 3->3? nop
}; 
//notice how the err's are on the diagonal?
//and the nops are on the other diagonal?
//and the inc and dec form a sort of circle?

// Update count based on encoder state changes
// https://cdn.sparkfun.com/datasheets/Robotics/How%20to%20use%20a%20quadrature%20encoder.pdf
// FYI, there are a lot of REALLY BAD examples out there which don't work, or are overly complex.
int8_t quad_slots2count(int8_t new_a_state, int8_t new_b_state) {
  //combine a and b, by making b into 2nd bit; value of 0 or 2
  int8_t new_state = new_a_state + 2*new_b_state;
  // 0 = 00 = a0 + b0
  // 1 = 01 = a1 + b0
  // 2 = 10 = a0 + b2
  // 3 = 11 = a1 + b2
  //index the Quadrature Encoder Matrix by old and new state
  //make the old state the 4th and 5th bits
  int8_t action = QEM[new_state + 4*old_state];
  old_state = new_state; //time has passed, new is old
  if (action == 2) { //err: Both bits changed so we missed which one changed first
    count = 0; //and so we don't know the count
    return -1; //FAIL! Need faster microcontroller or a slower motor / encoder
  }
  count += action; //inc, dec, or nop the count
  //will it actually ever be nop?
  return 0; //success. count is global.
}

void setup() {
  Serial.begin(BAUD);
  while(!Serial); //Wait until the serial port is opened
  n = 0;
  pinMode(SIN_LED, OUTPUT);
  analogWrite(SIN_LED,220);
  sincenter = 512;
  pinMode(COS_LED, OUTPUT);
  analogWrite(COS_LED,240);
  coscenter = 512;
  //pinMode(SIN_ADC, INPUT_PULLUP); NO! DO NOT. USE EXTERNAL PULLUPS
  //pinMode(COS_ADC, INPUT_PULLUP); NO! DO NOT. USE EXTERNAL PULLUPS
  //Serial.println("Hello World!");
  count = 0;
}

unsigned long lastMilli = 0;

void loop() {
  int sin = analogRead(SIN_ADC);
  int cos = analogRead(COS_ADC);
  //subtract center values to provide positive and negative input
  int sin_sign = sin-sincenter;
  int cos_sign = cos-sincenter;
  // which goes into atan2 and gives us the quadrant.
  //The output scale will be +-Pi, so scale as desired. In this case, for graphing w/adc
  int a = (atan2(sin_sign, cos_sign)/(2*M_PI))*1024+512;
  quad_slots2count(sin_sign>0, cos_sign>0);
  if(millis()-lastMilli > 50){ 
    lastMilli = millis();
    Serial.print("0, 1024, "); //just to set the scale
    Serial.print(cos);
    Serial.print(",");
    Serial.print(sin);
    Serial.print(",");
    Serial.print(a);
    Serial.print(",");
    Serial.print(count);
    Serial.print("\n");
  } //finished with timed update.
  if (Serial.available() > 0) { //manage any incomming serial input
    c = (char)Serial.read(); //get the character
    if (isdigit(c)) { //if it's a digit
      n *= 10; //sift the prior digits up
      n += (c - '0'); //convert ascii to int and add
    } else { //not a number
      switch(c){
        case 'S': //command to set the PWM output to the LED
          analogWrite(SIN_LED, n);
          break;
        case 's': //command to set the center point of the ADC range
          sincenter = n;
          break;
        case 'C':
          analogWrite(COS_LED, n);
          break;
        case 'c':
          coscenter = n;
          break;
      }
      n = 0; //because we got a command, now it's time to clear the value for next time
    } //finished managing commands. Note invalid command clear the number
  } //finished managing serial input.
}
