

/////////////// DTH11 //////////////////
#include <dht11.h>
 
dht11 DHT11;
 
#define DHT11PIN 13    //przypisanie pinu 13 Arduino jako odczyt z sensora

///////////////////////////////////////

/////////////////// Termometr ds1820B //
#include <OneWire.h>
#include <DS18B20.h>
const byte ONEWIRE_PIN = 2; //Pin 1-wire do którego jest podłączona szyna danych przez rezystor 4.7 kohm
const byte SENSORS_NUM = 1; // ilosc czujnikow

byte sensorAddress[8] = {0x28, 0x3C, 0x8B, 0x3, 0x0, 0x0, 0x80, 0x31};
// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);
float temperatura1 ;

////////////////////////////////////////

///////////////////// wifi ////////////////////////
#include <SoftwareSerial.h>
SoftwareSerial ESP8266(10,11);//RX,TX
#define IP "184.106.153.149" // thingspeak.com IP address
String API = "3NQEALXD084BWSTJ"; //klucz thingspeak.com
String GET = "GET https://api.thingspeak.com/update?api_key="+API+"";
String field1="&field1=";
String field2="&field2=";
String field3="&field3=";
String field4="&field4=";
String sklejony;
///////////////////////////////////////////
unsigned long czas = 0;
unsigned long x = 0 ;


void setup() {

 
//////////////// DTH11 ////////////////
  Serial.begin(9600);                    //inicjalizacja monitora szeregowego
  Serial.println("Program testowy DHT11"); 
  Serial.println();

///////////////////////////////////////

/////////////// ds1820b //////////////////
// Inicjalizacja czujnikow
  sensors.begin(11);

// Wyslanie pierwszej prosby o pomiar
  sensors.request();
  delay(100);

////////////////////////////////////////

////////////////wifi///////////////////
ESP8266.begin(9600);
  if(wyslij("AT+RST","ready",1000))     //wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania)
  Serial.println("Restart - OK!");
  if(wyslij("AT+CIPMUX=0","OK",1000))
  Serial.println("CIPMUX - OK!");  
  if(wyslij("AT+CWMODE=1","OK",1000))
  Serial.println("CWMODE - OK!");
  if(wyslij("AT+CWDHCP=1,1","OK",1000))
  Serial.println("DHCP - OK!");
  if(wyslij("AT+CWJAP=\"Necik\",\"bodnar5732436\"","OK",5000))
  Serial.println("Polaczenie wifi - OK!");
  
///////////////////////////////////////

}

void loop() {

  if ( (millis()-czas) >= 1000 ){czas = millis();x++;}

      

pomiar_temp_dth11 ();
pomiar_temp_ds1820b ();
Serial.println(x);
if (x>=20)
{
wyslanie_do_tgingspeak ();


}}

void pomiar_temp_dth11 () {
  
int chk = DHT11.read(DHT11PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym
 
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
        Serial.print("OK\t"); 
        break;
    case DHTLIB_ERROR_CHECKSUM: 
        Serial.println("Blad sumy kontrolnej"); 
        break;
    case DHTLIB_ERROR_TIMEOUT: 
        Serial.println("Koniec czasu oczekiwania - brak odpowiedzi"); 
        break;
    default: 
        Serial.println("Nieznany błąd"); 
        break;
  }
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print((float)DHT11.humidity, 2);
  Serial.print("\t\t");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println((float)DHT11.temperature, 2);
 
                                //opóźnienie między kolejnymi odczytami - 1 s
  
 }

 void pomiar_temp_ds1820b () 
 {
sensors.request();
// = sensors.readTemperature(FA(sensorsAddress[0]));

  temperatura1  = sensors.readTemperature(sensorAddress);
  Serial.print("Temperatura2 (C): ");           //wyświetlenie temperatury
  Serial.println((float)temperatura1, 2);
  delay(1000);    
  }

boolean wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania){
  ESP8266.println(Komenda_AT);
  delay(czas_czekania);
  while(ESP8266.available()>0){
    if(ESP8266.find(Odpowiedz_AT)) {
    return 1;
    }     
  }
  return 0;
}

void wyslanie_do_tgingspeak ()
{
delay(1000);
  if(wyslij("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80","CONNECT",2000))     //wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania)
  Serial.println("CONNECT - OK!");

String sklejony = GET + field1 + temperatura1 + field2 + DHT11.temperature + field3 + DHT11.humidity;

    
  String cmd ="AT+CIPSEND=";
  cmd += String(sklejony.length()+1);
  ESP8266.println(cmd);
  delay(1000);
  if(ESP8266.find(">")){
    delay(1000);
  ESP8266.println(sklejony);
  Serial.println("wyslano");
  x=0;
  }    
  
}

