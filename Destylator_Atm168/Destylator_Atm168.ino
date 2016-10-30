//////////// TERMOMETRY DS1820B /////////////
#include <OneWire.h>
#include <DS18B20.h>
const byte ONEWIRE_PIN = 2; //Pin 1-wire do którego jest podłączona szyna danych przez rezystor 4.7 kohm
const byte SENSORS_NUM = 2; // ilosc czujnikow
const byte sensorsAddress[SENSORS_NUM][8] PROGMEM = {
  0x28, 0x3C, 0x8B, 0x3, 0x0, 0x0, 0x80, 0x31,
  0x28, 0xCD, 0x8D, 0x3, 0x0, 0x0, 0x80, 0xE8
}; // Adresy
// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adres wyświetlacza i jego rozmiar
int tempAlarm = 30; // temperatura po której przekroczeniu uruchamia się alarm
#include <SoftwareSerial.h>
SoftwareSerial ESP8266(10, 11); //RX,TX
#define IP "184.106.153.149" // thingspeak.com IP address
unsigned long czas = 0;
unsigned long x = 0 ;
void setup() {
  Serial.begin(9600);
  sensors.begin(11);
  sensors.request();
  lcd.init();  // Inicjalizacja LCD
  lcd.backlight();
  ESP8266.begin(9600);
  if (wyslij("AT+RST", "ready", 1000))  //wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania)
    if (wyslij("AT+CIPMUX=0", "OK", 1000))
      if (wyslij("AT+CWMODE=1", "OK", 1000))
        if (wyslij("AT+CWDHCP=1,1", "OK", 1000))
          if (wyslij("AT+CWJAP=\"Necik\",\"bodnar5732436\"", "OK", 5000))
   
           delay(10);
}


void loop() {
  sensors.request();
  float temperatura0 = 0;
    float temperatura1 = 0;
 
temperatura0 = sensors.readTemperature(FA(sensorsAddress[0]));
    temperatura1 = sensors.readTemperature(FA(sensorsAddress[1]));
  
    
    if ( (millis() - czas) >= 1000 ) {
      czas = millis();
      x++;
    }
    if ((temperatura0 >= tempAlarm) || (temperatura1 >= tempAlarm))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" ALARM! t>98");
      lcd.setCursor(13, 0);
      lcd.print("C");
      lcd.setCursor(0, 1);
      lcd.print("Wylacz palnik");
      delay(500);
//      int i = 0;
//      while (i = 20)
//      {
//        tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie A5
//        delay(150);
//        tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie A5
//        delay(150);
//        i++;
//      }
//      noTone(8);
      lcd.clear();

    }
    if ((temperatura0 > -273) || (temperatura1 > -273))
    {
      lcd.setCursor(0, 0);
      lcd.print("Szczyt 1:");
      lcd.setCursor(0, 1);
      lcd.print("Kociol 2:");
      lcd.setCursor(15, 0);
      lcd.print("C");
      lcd.setCursor(15, 1);
      lcd.print("C");
      lcd.setCursor(9, 0);
      lcd.print(temperatura0);
      lcd.setCursor(9, 1);
      lcd.print(temperatura1);

      if (x >= 20) {

        String API = "3NQEALXD084BWSTJ"; //klucz thingspeak.com
        String GET = "GET https://api.thingspeak.com/update?api_key=" + API + "";
        String field1 = "&field1=";
        String field2 = "&field2=";
        String sklejony;
        String cmd = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80";
        ESP8266.println(cmd);
        delay(200);
        cmd = "AT+CIPSEND=";
        cmd += String(sklejony.length() + 1);
        ESP8266.println(cmd);
        delay(200);
        if (ESP8266.find(">")) {
          delay(200);
          ESP8266.println(sklejony);
          x = 0;
        }


      }
    }
    Serial.println(temperatura1);
    delay(200);
  }


boolean wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania) {
  Serial.println(Komenda_AT);
  delay(czas_czekania);
  while (Serial.available() > 0) {
    if (Serial.find(Odpowiedz_AT)) {
      return 1;
    }
  }
  return 0;
}




