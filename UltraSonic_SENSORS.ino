int trigPin=9;//transmits sound waves
int echoPin=10;//receives the sound wave when got hit by any object
float distance,duration;//to store the value of distance and time
void setup(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}
void loop(){
digitalWrite(trigPin, LOW);//Default value for trigpin
delay(10);
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);

duration=pulseIn(echoPin, HIGH);
distance= duration*0.0343/2;
Serial.println("The distance is: ");
Serial.print(distance );
Serial.print("cm");
}