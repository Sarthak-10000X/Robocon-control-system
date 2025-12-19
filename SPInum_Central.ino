#include <SPI.h>
int receivedNum;
bool flag=false;//used for interrupt to work very fast
// Using interrupts so that the spi speed doesnt affect the messsage
ISR(SPI_STC_vect){
  receivedNum=SPDR; //data registers in the variable
  flag=true;
}
void setup() {
 Serial.begin(9600);
 pinMode(MISO,OUTPUT);// slave line , slave sends data to master.
 SPCR |=_BV(SPE);

SPI.attachInterrupt();
}

void loop() {
  if(flag){
    Serial.print("Message received: ");
    Serial.println(receivedNum);
    flag=false;
  }

}