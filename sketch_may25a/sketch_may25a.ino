volatile int state = LOW;
int ledArray[] = {3,4,6};
int count = 0;
int timer = 150;
int pause=500;


void setup() {
  // put your setup code here, to run once:
for (count=0; count<3; count++) {pinMode(ledArray[count], OUTPUT);
}
attachInterrupt(0, ledOnOff, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
if (state){
  for (count=0; count<3; count++) {

  digitalWrite(ledArray[count], HIGH);
  delay(timer);
}
delay(pause);
for (count=0; count<3; count++){
  digitalWrite(ledArray[count],LOW);
  delay(timer);
}
delay(pause);
}
}
void ledOnOff(){
  static unsigned long lastMills=0;
  unsigned long newMills=millis();
  if (newMills-lastMills <50){
    
  }
  else{
    state=!state;
    lastMills=newMills;
  }
  }

