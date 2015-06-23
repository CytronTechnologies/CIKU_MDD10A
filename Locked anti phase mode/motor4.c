
#include "Arduino.h"

#define pwm_2 4
#define pwm_1 7
#define dir_2 5
#define dir_1 6
#define pot A1

void setup() {
// define pin name
pinMode(dir_1, OUTPUT);
pinMode(dir_2, OUTPUT);
pinMode(pwm_1, OUTPUT);
pinMode(pwm_2, OUTPUT);
pinMode(pot,INPUT);
Serial_begin(9600);
}

void loop() {
int reading = 0;
int output=0;
int opposite_output=0;
digitalWrite(pwm_1,HIGH);
digitalWrite(pwm_2,HIGH);

for (int i=0;i<5;i++)
reading+= analogRead(pot);
output=reading/5;
opposite_output=1023-output;
analogWrite(dir_2,output);
analogWrite(dir_1,opposite_output);
delay(30);
Serial_printString("DIR");
Serial_println();
Serial_printNumber(output,DEC);
}
