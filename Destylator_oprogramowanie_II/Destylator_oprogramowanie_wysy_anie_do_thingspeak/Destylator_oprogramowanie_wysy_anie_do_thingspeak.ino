//////////// TERMOMETRY DS1820B /////////////
#include <OneWire.h>
#include <DS18B20.h>
const byte ONEWIRE_PIN = 2; //Pin 1-wire do którego jest podłączona szyna danych przez rezystor 4.7 kohm
const byte SENSORS_NUM = 2; // ilosc czujnikow
const byte sensorsAddress[SENSORS_NUM][8] PROGMEM = {
0x28, 0x3C, 0x8B, 0x3, 0x0, 0x0, 0x80, 0x31,
0x28, 0xCD, 0x8D, 0x3, 0x0, 0x0, 0x80, 0xE8}; // Adresy
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
LiquidCrystal_I2C lcd(0x27,16,2);  // Adres wyświetlacza i jego rozmiar
byte customChar[8] = {
  0b00010,
  0b00101,
  0b00010,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
/////////////////////////////////////////////

//////////// BUZZER ////////////////////////
#define BPM 120
#define Q 60000/BPM
#define S Q/4
#define E Q/2
#define S Q/4
#define H 2*Q
#define E4  329.63
#define C4  261.63
#define LA3 220.00
#define F3  174.61
#define F4  349.23
#define Ab3 207.65
////////////////////////////////////////////

//////////// ALARM ////////////////////////

int tempAlarm =98; // temperatura po której przekroczeniu uruchamia się alarm


////////////////////////////////////////////


void setup() {


//////////// WYSWIETLACZ ////////////////////
lcd.init();  // Inicjalizacja LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Inicjalizacja");
  lcd.setCursor(0,1);
  lcd.print("systemu");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("Inicjalizacja");
  lcd.setCursor(0,1);
  lcd.print("czujnikow");
  lcd.createChar(0, customChar);
  delay(3000);
  
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
          lcd.setCursor(0,0);
          lcd.print("Czujnik 1 ");
          lcd.setCursor(0,1);
          lcd.print(" jest niegotowy");
          delay(3000);
          lcd.clear();
          }
if (temperatura1 == -273.15)
          {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Czujnik 2 ");
          lcd.setCursor(0,1);
          lcd.print(" jest niegotowy");
          delay(3000);
          lcd.clear();
          }
if (temperatura0 != -273.15)
          {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Czujnik 1 ");
          lcd.setCursor(0,1);
          lcd.print(" jest gotowy");
          delay(3000);
          lcd.clear();
          }
if (temperatura1 != -273.15)
          {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Czujnik 2 ");
          lcd.setCursor(0,1);
          lcd.print(" jest gotowy");
          delay(3000);
          lcd.clear();
          }
//////////// BUZZER ////////////////////////
lcd.setCursor(0,0);
  lcd.print("Test");
  lcd.setCursor(0,1);
  lcd.print("alarmu");
  delay(1000);

pinMode(8, OUTPUT);  

    tone(8,LA3,Q); // muzyczka na init
    delay(1+Q); 
    tone(8,LA3,Q);
    delay(1+Q);
    tone(8,LA3,Q);
    delay(1+Q);
    tone(8,F3,E+S);
    delay(1+E+S);
    tone(8,C4,S);
    delay(1+S);
    
    
    tone(8,LA3,Q);
    delay(1+Q);
    tone(8,F3,E+S);
    delay(1+E+S);
    tone(8,C4,S);
    delay(1+S);
    tone(8,LA3,H);
    delay(1+H);
     
    
    tone(8,E4,Q); 
    delay(1+Q); 
    tone(8,E4,Q);
    delay(1+Q);
    tone(8,E4,Q);
    delay(1+Q);
    tone(8,F4,E+S);
    delay(1+E+S);
    tone(8,C4,S);
    delay(1+S);
    
    tone(8,Ab3,Q);
    delay(1+Q);
    tone(8,F3,E+S);
    delay(1+E+S);
    tone(8,C4,S);
    delay(1+S);
    tone(8,LA3,H);
    delay(1+H);
    
    noTone(8);
   
  delay(1000);
  lcd.clear();

////////////////////////////////////////////

//////////// WYSWIETLACZ ////////////////////
  lcd.setCursor(0,0);
  lcd.print("Panoramiksie"); // to trzeba dac na koniec setupu
  lcd.setCursor(0,1);
  lcd.print("garnek gotowy");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Szczyt 1:");
  lcd.setCursor(0,1);
  lcd.print("Kociol 2:");
  lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(15,1);
  lcd.print("C");
  lcd.setCursor(14,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(14,1);
  lcd.write((uint8_t)0);
  

  
  
/////////////////////////////////////////////

}

void loop() {
sensors.request();
temperatura0 = sensors.readTemperature(FA(sensorsAddress[0]));
temperatura1 = sensors.readTemperature(FA(sensorsAddress[1]));

if ((temperatura0>=tempAlarm) || (temperatura1>=tempAlarm))
{
  Alarm();
//  goto koniec;
}

//if (temperatura1>=tempAlarm)
//{
//  Alarm();
//  goto koniec;
//  
//}
else

  {
    
  lcd.setCursor(0,0);
  lcd.print("Szczyt 1:");
  lcd.setCursor(0,1);
  lcd.print("Kociol 2:");
  lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(15,1);
  lcd.print("C");
  lcd.setCursor(14,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(14,1);
  lcd.write((uint8_t)0);
if (temperatura0 != -273.15)
{
  lcd.setCursor(9,0);
lcd.print(temperatura0);
  }
if (temperatura1 != -273.15)
{
  lcd.setCursor(9,1);
lcd.print(temperatura1);
  }

if (temperatura0 == -273.15)
{
  lcd.setCursor(9,0);
lcd.print("b/d");
}

if (temperatura1 == -273.15)
{
  lcd.setCursor(9,1);
lcd.print("b/d");
}
  }
//koniec:;

}


//////////////////Funkcje//////////////////


//////////// FUNKCA  ALARM ////////////////////////
void Alarm ()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" ALARM! t>98");
  lcd.setCursor(12,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(13,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Wylacz palnik");
  delay(500);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  noTone(8);
  

 
  lcd.clear();
  

}
////////////////////////////////////////////
