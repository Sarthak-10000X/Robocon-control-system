//single interrupt
int pinA=2;
int pinB=4;
int count=0;
void setup(){
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pinA), enInterrupt, RISING);
}
void loop(){
  noInterrupts();
  int encodercount=count;
  interrupts();
 // while(Serial.available()==0);
  Serial.print("position: ");
  Serial.println(encodercount);
  delay(100);
}
void enInterrupt(){
  if(digitalRead(pinB)==HIGH){
    count++;
  }else{
    count--;
  }
}