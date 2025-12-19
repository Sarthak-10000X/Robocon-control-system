void setup(){
Serial.begin(9600);
Serial1.begin(9600);
}
void loop(){
while(Serial1.available()==0);
String receive=Serial1.readString();
Serial.print("Received: ");
Serial.println(receive);
}