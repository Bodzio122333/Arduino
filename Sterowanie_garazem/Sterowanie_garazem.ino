#define przekaznik 3 
#define wlacznik 4 

void setup() {

pinMode(przekaznik, OUTPUT);
pinMode(wlacznik, INPUT_PULLUP);
digitalWrite(przekaznik, HIGH);

}

void loop() {


  if(digitalRead(wlacznik) == LOW)                      
  { 
    delay(20);
    if(digitalRead(wlacznik) == LOW)
    digitalWrite(przekaznik, LOW);
    delay(200);
    digitalWrite(przekaznik, HIGH);
    while (digitalRead(wlacznik) == LOW);
    delay(1000);
  }}

