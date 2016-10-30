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
float temperatura0;
float temperatura1;
/////////////////////////////////////////////

//////////// WYSWIETLACZ ////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adres wyświetlacza i jego rozmiar
//byte customChar[8] = {
//  0b00010,
//  0b00101,
//  0b00010,
//  0b00000,
//  0b00000,
//  0b00000,
//  0b00000,
//  0b00000
//};
/////////////////////////////////////////////

//////////// BUZZER ////////////////////////

//#define BPM 120
//#define Q 60000/BPM
//#define S Q/4
//#define E Q/2
//#define S Q/4
//#define H 2*Q
//#define E4  329.63
//#define C4  261.63
//#define LA3 220.00
//#define F3  174.61
//#define F4  349.23
//#define Ab3 207.65

////////////////////////////////////////////

//////////// ALARM ////////////////////////

byte tempAlarm = 98; // temperatura po której przekroczeniu uruchamia się alarm

////////////////////////////////////////////

///////////////////// Wysyłanie danych do Thing Speak ///////////////
#include <SoftwareSerial.h>
SoftwareSerial ESP8266(10, 11); //RX,TX
#define IP "184.106.153.149" // thingspeak.com IP address
String API = "3NQEALXD084BWSTJ"; //klucz thingspeak.com
String GET = "GET https://api.thingspeak.com/update?api_key=" + API + "";
String field1 = "&field1=";
String field2 = "&field2=";
//String field3 = "&field3=";
//String field4 = "&field4=";
String sklejony;
unsigned czas = 0;
unsigned  x = 0 ;
///////////////////////////////////////////////////////////////



void setup() {


  //////////// WYSWIETLACZ ////////////////////
  lcd.init();  // Inicjalizacja LCD
  lcd.backlight();
//lcd.setCursor(0, 0);
//lcd.print("Inicjalizacja");
// lcd.setCursor(0, 1);
// lcd.print("systemu");
// delay(3000);
//  lcd.setCursor(0, 0);
//  lcd.print("Inicjalizacja");
//  lcd.setCursor(0, 1);
//  lcd.print("czujnikow");
//  lcd.createChar(0, customChar);
//  delay(3000);

  /////////////////////////////////////////////

  // Inicjalizacja czujnikow
  sensors.begin(11);

  // Wyslanie pierwszej prosby o pomiar
  sensors.request();
  delay(100);
  temperatura0 = sensors.readTemperature(FA(sensorsAddress[0]));
  temperatura1 = sensors.readTemperature(FA(sensorsAddress[1]));


  if (temperatura0 == -273.15)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Czujnik 1 ");
//    lcd.setCursor(0, 1);
//    lcd.print(" jest niegotowy");
    delay(3000);
    lcd.clear();
  }
  if (temperatura1 == -273.15)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Czujnik 2 ");
//    lcd.setCursor(0, 1);
//    lcd.print(" jest niegotowy");
    delay(3000);
    lcd.clear();
  }
  if (temperatura0 != -273.15)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Czujnik 1 ");
//    lcd.setCursor(0, 1);
//    lcd.print(" jest gotowy");
    delay(3000);
    lcd.clear();
  }
  if (temperatura1 != -273.15)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Czujnik 2 ");
//    lcd.setCursor(0, 1);
//    lcd.print(" jest gotowy");
    delay(3000);
    lcd.clear();
  }
  //////////// BUZZER ////////////////////////

//  lcd.setCursor(0, 0);
//  lcd.print("Test");
//  lcd.setCursor(0, 1);
//  lcd.print("alarmu");
//  delay(1000);
//
//  pinMode(8, OUTPUT);
//
//  tone(8, LA3, Q); // muzyczka na init
//  delay(1 + Q);
//  tone(8, LA3, Q);
//  delay(1 + Q);
//  tone(8, LA3, Q);
//  delay(1 + Q);
//  tone(8, F3, E + S);
//  delay(1 + E + S);
//  tone(8, C4, S);
//  delay(1 + S);
//
//
//  tone(8, LA3, Q);
//  delay(1 + Q);
//  tone(8, F3, E + S);
//  delay(1 + E + S);
//  tone(8, C4, S);
//  delay(1 + S);
//  tone(8, LA3, H);
//  delay(1 + H);


//  tone(8, E4, Q);
//  delay(1 + Q);
//  tone(8, E4, Q);
//  delay(1 + Q);
//  tone(8, E4, Q);
//  delay(1 + Q);
//  tone(8, F4, E + S);
//  delay(1 + E + S);
//  tone(8, C4, S);
//  delay(1 + S);
//
//  tone(8, Ab3, Q);
//  delay(1 + Q);
//  tone(8, F3, E + S);
//  delay(1 + E + S);
//  tone(8, C4, S);
//  delay(1 + S);
//  tone(8, LA3, H);
//  delay(1 + H);
//
//  noTone(8);
//
//  delay(1000);
//  lcd.clear();

  ////////////////////////////////////////////

  //////////// WYSWIETLACZ ////////////////////
//  lcd.setCursor(0, 0);
//  lcd.print("Panoramiksie"); // to trzeba dac na koniec setupu
//  lcd.setCursor(0, 1);
//  lcd.print("garnek gotowy");
//  delay(4000);
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Szczyt 1:");
//  lcd.setCursor(0, 1);
//  lcd.print("Kociol 2:");
//  lcd.setCursor(15, 0);
//  lcd.print("C");
//  lcd.setCursor(15, 1);
//  lcd.print("C");
//  lcd.setCursor(14, 0);
//  lcd.write((uint8_t)0);
//  lcd.setCursor(14, 1);
//  lcd.write((uint8_t)0);
  /////////////////////////////////////////////

  ////////////// Wysyłanie do ThingSpeak////////////////
  ESP8266.begin(9600);
  if (wyslij("AT+RST", "ready", 1000))  //wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania)
//    Serial.println("Restart - OK!");
  if (wyslij("AT+CIPMUX=0", "OK", 1000))
//    Serial.println("CIPMUX - OK!");
  if (wyslij("AT+CWMODE=1", "OK", 1000))
//    Serial.println("CWMODE - OK!");
  if (wyslij("AT+CWDHCP=1,1", "OK", 1000))
//    Serial.println("DHCP - OK!");
  if (wyslij("AT+CWJAP=\"Necik\",\"bodnar5732436\"", "OK", 5000))
    Serial.println("Polaczenie wifi - OK!");
  /////////////////////////////////////////////////
}

void loop() {
  sensors.request();
  temperatura0 = sensors.readTemperature(FA(sensorsAddress[0]));
  temperatura1 = sensors.readTemperature(FA(sensorsAddress[1]));

  if ((temperatura0 >= tempAlarm) || (temperatura1 >= tempAlarm))
  {
    Alarm();
  }

  else

  {

    lcd.setCursor(0, 0);
    lcd.print("Szczyt 1:");
    lcd.setCursor(0, 1);
    lcd.print("Kociol 2:");
    lcd.setCursor(15, 0);
    lcd.print("C");
    lcd.setCursor(15, 1);
    lcd.print("C");
    lcd.setCursor(14, 0);
//    lcd.write((uint8_t)0);
    lcd.setCursor(14, 1);
//    lcd.write((uint8_t)0);
    if (temperatura0 != -273.15)
    {
      lcd.setCursor(9, 0);
      lcd.print(temperatura0);
    }
    if (temperatura1 != -273.15)
    {
      lcd.setCursor(9, 1);
      lcd.print(temperatura1);
    }

    if (temperatura0 == -273.15)
    {
      lcd.setCursor(9, 0);
      lcd.print("b/d");
    }

    if (temperatura1 == -273.15)
    {
      lcd.setCursor(9, 1);
      lcd.print("b/d");
    }
  }
  ///////////////// Odmierzanie czasu////////////////
  if ( (millis() - czas) >= 1000 ) {
    czas = millis();
    x++;
  }

  Serial.println(x);
  if (x >= 20)
  {
    wyslanie_do_tgingspeak ();


  }

}


//////////////////Funkcje//////////////////


//////////// FUNKCA  ALARM ////////////////////////
void Alarm ()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ALARM! t>98");
  lcd.setCursor(12, 0);
//  lcd.write((uint8_t)0);
  lcd.setCursor(13, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Wylacz palnik");
  delay(500);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
  delay(150);
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
//  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
//  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
//  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
//  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
//  delay(150);
//  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8
//  delay(150);
//  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8
  noTone(8);



  lcd.clear();


}
////////////////////////////////////////////

////////////////// Wysyłanie danych do ThingSpeak//////
void wyslanie_do_tgingspeak ()
{
  delay(1000);
  if (wyslij("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80", "CONNECT", 2000))  //wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania)
//    Serial.println("CONNECT - OK!");

  String sklejony = GET + field1 + temperatura0 + field2 + temperatura1;


  String cmd = "AT+CIPSEND=";
  cmd += String(sklejony.length() + 1);
  ESP8266.println(cmd);
  delay(1000);
  if (ESP8266.find(">")) {
    delay(1000);
    ESP8266.println(sklejony);
//    Serial.println("wyslano");
    x = 0;
  }

}

boolean wyslij(String Komenda_AT, char *Odpowiedz_AT, int czas_czekania) {
  ESP8266.println(Komenda_AT);
  delay(czas_czekania);
  while (ESP8266.available() > 0) {
    if (ESP8266.find(Odpowiedz_AT)) {
      return 1;
    }
  }
  return 0;
}


