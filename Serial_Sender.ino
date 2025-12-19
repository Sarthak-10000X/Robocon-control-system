void setup(){
Serial.begin(9600);
Serial1.begin(9600);
}
void loop(){
  while(Serial.available()==0);//check wheather buffer is empty or not
  String Message = Serial.readString();
  Serial1.write(Message);//send to the arduino board
  Serial.print("Message sent: ");//print it in our Serial monitor
  Serial.println(Message);
}