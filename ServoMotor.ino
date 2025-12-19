#include<Servo.h>
Servo Sarthak_servo;
int servopin=9;
int angle=60;
int speed=4;
void setup(){
Sarthak_servo.attach(servopin);
}


void loop(){
  int current=Sarthak_servo.read();
  while(current != angle){
    if(current != angle){
      current--;
    }
else{
    current++;
  }
  }
  
Sarthak_servo.write(current);
delay(speed);
}