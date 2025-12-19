//SPI master!!
#include <SPI.h>

void setup(){
SPI.begin();
pinMode(SS, OUTPUT);//intialized slave select pin
digitalWrite(SS, HIGH);//currently slave select disabled

Serial.begin(9600);
}
void loop(){
  while(Serial.available()==0);
  String msg=Serial.readStringUntil('\n');
digitalWrite(SS, LOW);//enabled slave 
const char *s=msg.c_str();
for(int i=0; s[i]!='\0'; i++){
  SPI.transfer(s[i]);
  Serial.print(s[i]);
}
Serial.println("\nMessage sent..");
digitalWrite(SS, HIGH);//disabled slave
delay(1000);


}