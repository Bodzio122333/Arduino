int przekaznik = 3; 
int wlacznik = 4; 

void setup() {

pinMode(przekaznik, OUTPUT);
pinMode(wlacznik, INPUT_PULLUP);
digitalWrite(przekaznik, HIGH);
 //Serial.begin(9600); /
}

void loop() {

  bool syg_wl = digitalRead(wlacznik);
  if(syg_wl == LOW)                      
  {                                     
     
     digitalWrite(przekaznik, LOW);
     delay(200);
     digitalWrite(przekaznik, HIGH);
  }  
  
//Serial.println(syg_wl); 

}
