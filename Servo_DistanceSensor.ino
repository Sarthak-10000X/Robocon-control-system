#include<Servo.h>
Servo Sarthak_Servo;


int servopin=9;
int distpin=0;
void setup(){
  Sarthak_Servo.attach(servopin);
  
}
void loop(){
  //rotating 20 degress in servo motor
 int distance=analogRead(distpin);
  int position=map(distance, 0,1023,0,180);
   Sarthak_Servo.write(position);
  }
