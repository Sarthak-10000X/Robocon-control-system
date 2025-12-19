#include <Wire.h>
#include <String.h>
char receiveMsg[50];
String message="";
int i=0;
void setup(){
Serial.begin(9600);
Wire.begin(0x21);
Wire.onReceive(loop);
}
void loop(){
  while(Wire.available()==0);
  for(int i=0; i<message.length()+1 ; i++){
    receiveMsg[i]= Wire.read();
    if(i < sizeof(receiveMsg)){
      message += receiveMsg[i];
    }
  }
  Serial.print("Message received: ");
  Serial.println(message);
  message='\0';
}