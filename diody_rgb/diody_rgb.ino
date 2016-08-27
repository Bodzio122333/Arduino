void setup() {                
  // pin 8 ma pracowac jako wyjscie
  pinMode(3, OUTPUT);   
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);   
 
}
 
void loop() {
  // wlaczenie diody
  digitalWrite(3, HIGH);
 
  // odczekanie pol sekundy
  delay(50);
 
  // wylaczenie diody
  digitalWrite(3, LOW);
 
  // odczekanie pol sekundy
  delay(50);
   // wlaczenie diody
  digitalWrite(5, HIGH);
 
  // odczekanie pol sekundy
  delay(50);
 
  // wylaczenie diody
  digitalWrite(5, LOW);
 
  // odczekanie pol sekundy
  delay(50);
   // wlaczenie diody
  digitalWrite(6, HIGH);
 
  // odczekanie pol sekundy
  delay(50);
 
  // wylaczenie diody
  digitalWrite(6, LOW);
 
  // odczekanie pol sekundy
  delay(50);
}
