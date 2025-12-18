int R_IS=1;
int R_EN=2;
int RPWM=3;
int L_IS=4;
int L_EN=5;
int LPWM=6;
void setup(){
pinMode(R_IS, OUTPUT);
pinMode(R_EN, OUTPUT);
pinMode(RPWM, OUTPUT);
pinMode(L_IS, OUTPUT);
pinMode(L_EN, OUTPUT);
pinMode(LPWM, OUTPUT);
digitalWrite(R_IS,LOW);
digitalWrite(L_IS, LOW);
digitalWrite(L_EN, HIGH);
digitalWrite(R_EN, HIGH);
}
void loop(){
for(int i=0; i<=255; i++){//clockwise
  analogWrite(RPWM, i);
  analogWrite(LPWM, 0);
  delay(20);
}
delay(500);
for(int i=0; i<=255; i++){//anti clockwise
  analogWrite(RPWM, 0);
  analogWrite(LPWM, i);
  delay(20);
}
delay(500);

}