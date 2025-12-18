int IN1=4;
int IN2=5;
int IN3=1;
int IN4=2;

int ENB=9;
int ENA=10;
void setup(){
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
}
void loop(){
   analogWrite(ENA, 255);
   analogWrite(ENB, 255);
  //forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2,LOW); 
  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,HIGH); 
  
  delay(3000);
  //reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW); 
  delay(3000);
}