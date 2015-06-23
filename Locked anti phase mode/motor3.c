
#include "Arduino.h"

// define pin name
#define pwm_2 4
#define pwm_1 7
#define dir_2 5
#define dir_1 6
void setup() {
pinMode(pwm_2, OUTPUT);
pinMode(pwm_1, OUTPUT);
pinMode(dir_1, OUTPUT);
pinMode(dir_2, OUTPUT);
Serial_begin(9600);
Serial_printString("DIR");
}

void loop() {
int pwm_value = 0;
int opposite_i;
digitalWrite(pwm_1,HIGH);
digitalWrite(pwm_2,HIGH);

for(int i=0;i<=1023;i++){
analogWrite(dir_1,i);
opposite_i=255-i;
analogWrite(dir_2,(1023-i));
delay(30);
Serial_write(i);
Serial_println();
}
while(1)
continue;
}