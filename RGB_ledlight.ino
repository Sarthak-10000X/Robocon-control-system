int RED_pin=11;
int BLUE_pin=10;
int GREEN_pin=9;
int button_pin=2;
bool lastButton=HIGH;
int ledstate=0;
bool currentButton=HIGH;
void setup()
{
  pinMode(RED_pin, OUTPUT);
  pinMode(BLUE_pin, OUTPUT);
  pinMode(GREEN_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  setLED(255,255,255);
}

void loop()
{
  currentButton=digitalRead(button_pin);
  if(lastButton==HIGH && currentButton==LOW){
    delay(100);
    ledstate=ledstate+1;
    if(ledstate>3)ledstate=0;
  }
  switch(ledstate){
    case(0):setLED(255,255,255);break;
    case(1):setLED(0,255,255);break;
    case(2):setLED(255,0,255);break;
    case(3):setLED(255,255,0);break; 
  }
  lastButton=currentButton;
}
void setLED(int REDval,int BLUEval,int GREENval){
  analogWrite(RED_pin, REDval);
  analogWrite(BLUE_pin, BLUEval);
  analogWrite(GREEN_pin, GREENval);
}
