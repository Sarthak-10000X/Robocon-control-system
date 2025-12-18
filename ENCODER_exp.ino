
#include<Servo.h>
Servo sarthak;
int inputclk=6;//channel A
int inputdt=7;//channel B
int redPin=11;
int bluePin=10;
int currentState;
int previousState;
int counter=0;
void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin,OUTPUT);
  sarthak.attach(9);
  pinMode(inputclk, INPUT);
  pinMode(inputdt,INPUT);
Serial.begin(9600);
previousState=digitalRead(inputclk);
}
void loop(){
  analogWrite(redPin, 255);
  analogWrite(bluePin, 255);
  currentState=digitalRead(inputclk);
  if(currentState != previousState){
    if(digitalRead(inputdt) != currentState){//counter clock wise
       counter--;
       analogWrite(redPin, 0);
      if(counter < 0){
        counter=0;
      
    
    }else{
      counter++;
      analogWrite(bluePin,0);
      if(counter > 180){//clock wise
        counter=180;
      }
     
    }
    //to move the servo!
    sarthak.write(counter);
    Serial.print("position: ");
    Serial.println(counter);
  }
 
   
  previousState=currentState;
}