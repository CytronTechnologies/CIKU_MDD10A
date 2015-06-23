
#include "Arduino.h"

//define pin name
#define dir_1 7
#define pwm_1 6
#define switch_1 13
#define switch_2 12
#define dir_2 4
#define pwm_2 5
#define pot A1 //potentiometer

void setup(){
//declare pins as INPUT/OUTPUT
pinMode(pwm_1,OUTPUT);
pinMode(dir_1,OUTPUT);
pinMode(pwm_2,OUTPUT);
pinMode(dir_2,OUTPUT);
pinMode(pot,INPUT);
pinMode(switch_1, INPUT);
pinMode(switch_2, INPUT);
Serial_begin(9600); //I am using Serial Monitor instead of LCD display
}
void loop(){
int pwm_value;
for (pwm_value=0;pwm_value<=1023;pwm_value++){
digitalWrite(dir_1,digitalRead(switch_1)); //controls the direction the motor
digitalWrite(dir_2,!digitalRead(switch_2));
analogWrite(pwm_2,pwm_value); //increase the speed of the motor from 0 to 255
analogWrite(pwm_1,(1023-pwm_value)); //decrease the speed of the motor from 255 to 0
Serial_printString("PWM:");
Serial_println();
Serial_write(pwm_value); //Display the value of PWM
Serial_println();
delay(50);
}

while(1) continue; //terminate the program
}