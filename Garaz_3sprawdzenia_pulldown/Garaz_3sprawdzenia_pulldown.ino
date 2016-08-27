#define przekaznik 3 
#define wlacznik 4 

void setup() {

pinMode(przekaznik, OUTPUT);
pinMode(wlacznik, INPUT); // dajemy na przycisku podciągnięcie do masy rezystorem
digitalWrite(przekaznik, HIGH);

}

void loop() {


  if(digitalRead(wlacznik) == HIGH)       //wyzwalamy sygnałem wysokim i sprawdzamy stan przycisku 3 razy             
  { 
    delay(20);
    
    if(digitalRead(wlacznik) == HIGH)
    {
      delay(20);
      if(digitalRead(wlacznik) == HIGH)
      {
          digitalWrite(przekaznik, LOW);
          delay(200);
          digitalWrite(przekaznik, HIGH);
          while (digitalRead(wlacznik) == LOW);
          delay(1000);
      }
      delay(1000);
      }
      delay(1000);
      }}

