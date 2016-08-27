int czujnik = 8;   //pin 8 połączony z sygnałem z czujnika
int przekaznik = 7; 
int czas=0;
int minuty = 5;


void setup(){
  Serial.begin(9600);        //inicjalizacja monitora szeregowego
  pinMode(czujnik, INPUT);   //ustawienie pinu Arduino jako wejście
  pinMode(przekaznik, OUTPUT); 
  Serial.println("---- TEST CZUJNIKA RUCHU ----"); 
  digitalWrite(przekaznik, HIGH);
  
}
 
void loop(){

  
  int ruch = digitalRead(czujnik);      //odczytanie wartości z czujnika
  if(ruch == HIGH)                      //wyświetlenie informacji na monitorze szeregowym
  {                                     //stan wysoki oznacza wykrycie ruchu, stan niski - brak ruchu
   czas=(60*minuty);
      
  }

if(czas>=0)
{
  digitalWrite(przekaznik, LOW);
}
if(czas<=0)
{
  digitalWrite(przekaznik, HIGH);
}
Serial.println(czas); 
czas=czas-1;
delay(1000);


}


