#define przekaznik 6 
#define wlacznik 4 

void setup() {

pinMode(przekaznik, OUTPUT);
pinMode(wlacznik, INPUT_PULLUP); // dajemy na przycisku podciągnięcie do masy rezystorem
digitalWrite(przekaznik, HIGH);

}

void loop() {


  if(digitalRead(wlacznik) == LOW)       //wyzwalamy sygnałem wysokim i sprawdzamy stan przycisku 3 razy             
  { 
    delay(20);
    
    if(digitalRead(wlacznik) == LOW)
    {
      delay(20);
      if(digitalRead(wlacznik) == LOW)
      {
          digitalWrite(przekaznik, LOW);
          delay(500);
          digitalWrite(przekaznik, HIGH);
          while (digitalRead(wlacznik) == LOW);
          delay(1000);
      }
      delay(1000);
      }
      delay(1000);
      }}

