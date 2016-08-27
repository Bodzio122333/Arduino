volatile int state = 0;
int ledArray[] = {9,10};
int count = 0;
int timer = 150;
int stopLED=5;
int goLED=4;
int randMin=250;
int randMax=750;
int startDelay;
volatile unsigned long time;
unsigned long start_time;


void setup() {
  
  // put your setup code here, to run once:
for (count=0; count<2; count++) {
  pinMode(ledArray[count], OUTPUT);
}
attachInterrupt(1, ledOnOff, RISING);
pinMode(stopLED,OUTPUT);
pinMode(goLED,OUTPUT);
randomSeed(analogRead(0));
Serial.begin(9600);

}

void loop() {

  // put your main code here, to run repeatedly:
if (state==0){
  digitalWrite(stopLED,LOW);
  digitalWrite(goLED,HIGH);
  for (count=0; count<2; count++){
   digitalWrite(ledArray[count],LOW);
    }
}
if (state==1){
  startDelay=random(randMin,randMax);
  delay(startDelay);
  start_time=millis();
  digitalWrite(stopLED,HIGH);
  digitalWrite(goLED,LOW);
   
 
  for (count=0; count<2; count++) {
delay(timer);
if(state==2){
  time=(time-start_time)/1000;
  Serial.print("Czas reakcji: ");
  Serial.print(time);
  Serial.println("sek");
  delay(1000);
  break;
 }
  digitalWrite(ledArray[count], HIGH);
  }
  }
}
void ledOnOff(){
  static unsigned long lastMills=0;
  unsigned long newMills=millis();
  if (newMills-lastMills <50){
    
  }
  else{
    state=state++;
    if(state==2){
      time=millis();
     }
     if(state==3){
      state=0;
      
     }
    lastMills=newMills;
  }
  }
  

