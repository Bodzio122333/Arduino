/*
  RF_Sniffer
  
  Hacked from https://github.com/sui77/rc-switch
  
  by @justy to provide a handy RF code sniffer
*/

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int sygnal ;
int przekaznik =3;
int otw =16343640;
int zam =16343634;


void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(przekaznik, OUTPUT);
  digitalWrite(przekaznik, HIGH);
}
//int value = mySwitch.getReceivedValue();
void loop() {
  
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
   
     //Serial.print("Received ");
      Serial.println( mySwitch.getReceivedValue() );
      //Serial.print(" / ");
      //Serial.print( mySwitch.getReceivedBitlength() );
      //Serial.print("bit ");
     // Serial.print("Protocol: ");
     // Serial.println( mySwitch.getReceivedProtocol() );
    }
    if (value == otw) {
  digitalWrite(przekaznik, LOW);
}


if (value == zam) {
  digitalWrite(przekaznik, HIGH);
}

   mySwitch.resetAvailable();
    
  }
  


}

