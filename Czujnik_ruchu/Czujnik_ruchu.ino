int czujnik = 8;   //pin 8 połączony z sygnałem z czujnika
int przekaznik = 7; 
int czas=0;
int minuty = 5;
unsigned int godzina = 0;

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

if(czas>=0 && godzina > 10800 && godzina < 43200)
{
  digitalWrite(przekaznik, LOW);
}
if(czas<=0)
{
  digitalWrite(przekaznik, HIGH);
}
Serial.println(godzina); 
czas=czas-1;
delay(1000);
godzina=godzina+1;

if(godzina==86400)
{
  godzina=0;
}

}


