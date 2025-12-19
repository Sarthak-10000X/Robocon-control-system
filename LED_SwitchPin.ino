int switchpin=7;
int ledpin=11;
int led=0;
bool switchon=LOW;
bool currentbutton=LOW;
bool lastbutton=LOW;

bool dibounce(bool last){
  bool current=digitalRead(switchpin);
  if(last!=current){
    delay(10);
    current=digitalRead(switchpin);
  }
  return current;
 
}
void setup(){
  Serial.begin(9600);
  pinMode(switchpin, INPUT);
  pinMode(ledpin, OUTPUT);
}
void loop(){
  currentbutton=dibounce(lastbutton);
  if (lastbutton==LOW && currentbutton== HIGH){
    led=led+51;
  
  }
  Serial.println(led);
  lastbutton=currentbutton;
  if(led>255)     led=0;
  analogWrite(ledpin,led);
}