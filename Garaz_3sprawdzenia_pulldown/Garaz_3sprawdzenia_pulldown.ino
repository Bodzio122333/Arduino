#define przekaznik 4 
#define wlacznik 14 

void setup() {

pinMode(przekaznik, OUTPUT);
pinMode(wlacznik, INPUT_PULLUP); // dajemy na przycisku podciągnięcie do masy rezystorem
digitalWrite(przekaznik, LOW);

}

void loop() {


  if(digitalRead(wlacznik) == LOW)       //wyzwalamy sygnałem wysokim i sprawdzamy stan przycisku 3 razy             
  { 
    delay(20);
    
    if(digitalRead(wlacznik) == LOW)
    {
      delay(10);
      if(digitalRead(wlacznik) == LOW)
      {
      delay(10);
    
      if(digitalRead(wlacznik) == LOW)
       {
          digitalWrite(przekaznik, HIGH);
          delay(500);
          digitalWrite(przekaznik, LOW);
          while (digitalRead(wlacznik) == LOW);
          delay(1000);
      }
      delay(1000);
      }
      delay(1000);
    }}}
     

