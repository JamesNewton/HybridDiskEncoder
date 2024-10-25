
#include <math.h>
#define BAUD 115200
//pin assignments
#define SIN_LED 16
#define COS_LED 17
#define SIN_ADC 26
#define COS_ADC 27

char c; //input characters
int n; //accumulator for numbers
int sincenter, coscenter; //center point on ADC scale for sine and cosine 

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
}


void loop() {
  int sin = analogRead(SIN_ADC);
  int cos = analogRead(COS_ADC);
  //subtract center values to provide positive and negative input which gives us the quadrant.
  //The output scale will be +-Pi, so scale as desired. In this case, for graphing w/adc
  int a = (atan2(sin-sincenter, cos-coscenter)/(2*M_PI))*1024+512;
  Serial.print("0, 1024, "); //just to set the scale
  Serial.print(cos);
  Serial.print(",");
  Serial.print(sin);
  Serial.print(",");
  Serial.print(a);
  Serial.print("\n");
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
  delay(100); //no need to go crazy right now. 

}
