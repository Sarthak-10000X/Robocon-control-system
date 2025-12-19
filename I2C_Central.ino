#include<Wire.h>
String c;
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{

  //receiving the message here 
  while(Serial.available()==0);
  String msg = Serial.readString();
  msg+=" ";
  Wire.beginTransmission(0x21);
  Wire.write(msg.c_str());
  Serial.println("Message sent...");
  Serial.println(msg);
  Wire.endTransmission();
  //delay(1000);
}