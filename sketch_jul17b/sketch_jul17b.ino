int czujnik = 8;   //pin 8 połączony z sygnałem z czujnika
int przekaznik = 7; 
//int czas_zwloki = 600000;
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
    Serial.println("RUCH WYKRYTY!");
    digitalWrite(przekaznik, LOW);
    //delay(czas_zwloki);
    delay(600000);
  }
  else  {Serial.println("brak ruchu");
  digitalWrite(przekaznik, HIGH);
  }
   
  //delay(200);                         //opóźnienie między kolejnymi odczytami
}
