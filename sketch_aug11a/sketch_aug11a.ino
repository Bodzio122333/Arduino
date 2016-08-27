int przekaznik = 3; 
int wlacznik = 4; 
int sygnal_pilot = 2;
void setup() {
  // put your setup code here, to run once:
pinMode(przekaznik, OUTPUT);
//pinMode(wlacznik, INPUT);
pinMode(wlacznik, INPUT_PULLUP);
pinMode(sygnal_pilot, INPUT);
digitalWrite(przekaznik, HIGH);
 //Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  bool syg_wl = digitalRead(wlacznik);
  if(syg_wl == LOW)                      
  {                                     
     
     digitalWrite(przekaznik, LOW);
     delay(200);
     digitalWrite(przekaznik, HIGH);
  }  
  bool syg_pilot = digitalRead(sygnal_pilot);
if(syg_pilot == HIGH)                      
  {                                     
      digitalWrite(przekaznik, LOW);
     delay(200);
     digitalWrite(przekaznik, HIGH);
  }
//Serial.println(syg_pilot); 

}
