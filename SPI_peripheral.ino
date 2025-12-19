//slave
#include <SPI.h>
volatile char receivedMsg;
volatile bool flag=false;
int index=0;
char arr[1000];
// Using interrupts so that the spi speed doesnt affect the messsage
ISR(SPI_STC_vect){
  receivedMsg=SPDR; //data registers in the variable
  if(index < sizeof(receivedMsg)){
    
    arr[index]=receivedMsg;
    index++;
    flag=true;
  }
  // bytes[index]='\0';
}
void setup() {
 Serial.begin(9600);
 pinMode(MISO,OUTPUT);// slave line , slave sends data to master.
 SPCR |=_BV(SPE);
 SPI.attachInterrupt();
}

void loop() {
  if(flag){
      // Serial.println("message received: ");
      Serial.print(receivedMsg);
      flag=false;
      index=0;
  }
}

