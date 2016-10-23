#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void){
  Serial1.begin(115200);
  Serial.begin(9600);

  while(!wyslij("AT","OK",100)){
  Serial.println("Błąd komunikacji z modułem");
  delay(1000);
  }
  
  delay(5000);
  
  if(wyslij("AT+CWMODE=1","OK",500))
  Serial.println("CWMODE - OK!");
  if(wyslij("AT+CIPMODE=0","OK",500))
  Serial.println("CIPMODE - OK!");  
  if(wyslij("AT+CIPMUX=1","OK",500))
  Serial.println("CIPMUX - OK!");
  
  if(wyslij("AT+CWJAP=\"ElektroPrzewodnik\",\"rezystancja\"","OK",5000))
  Serial.println("Polaczono z siecia!");
  
  if(wyslij("AT+CIPSERVER=1,80","OK",5000))
  Serial.println("Uruchomiono serwer :)");
  
  Serial1.println("AT+CIFSR");
  Serial.println(Serial1.readString());
  delay(200);
  
  sensors.begin();
}

char klient[1];
char bufor [50];
String strona;

void loop() {
  while(Serial1.available()>0)
  {
    if(Serial1.find("+IPD,"))
    {
      Serial1.readBytesUntil(',',klient,1);
      Serial.println();
      
      sensors.requestTemperatures();
      strona = "<html><head><title>TEST</title></head><body><h2>Temperatura: " + String(sensors.getTempCByIndex(0)) + "*C</h2></body></html>";
   
      Serial.print("ZAPYTANIE ID: ");
      Serial.println(klient[0]);
      
      sprintf(bufor,"AT+CIPSEND=%c,%d",klient[0],strona.length());
      if(wyslij(bufor,">",100))
      Serial.println("Zadanie wyslania...");
      if(wyslij(strona,"OK",100))
      Serial.println("Wyslano dane");
      sprintf(bufor,"AT+CIPCLOSE=%c",klient[0]);
      if(wyslij(bufor,"OK",100))
      Serial.println("Zamknieto polaczenie");
    } 
  }
}

boolean wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania){
  Serial1.println(Komenda_AT);
  delay(czas_czekania);
  while(Serial1.available()>0){
    if(Serial1.find(Odpowiedz_AT)) {
    return 1;
    }     
  }
  return 0;
}
  
