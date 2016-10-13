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
bool Term0OK =true;
bool Term1OK =true;
float temperature;
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

int tempAlarm =30; // temperatura po której przekroczeniu uruchamia się alarm


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



//////////// TERMOMETRY DS1820B /////////////
  // Uruchomienie serial portu
  while(!Serial);
  Serial.begin(9600);

  // Inicjalizacja czujnikow
  sensors.begin(11);

  // Wyslanie pierwszej prosby o pomiar
  sensors.request();
delay(100);
for (byte i=0; i<SENSORS_NUM; i++)
    {
      float temperature = sensors.readTemperature(FA(sensorsAddress[i]));

      // Prints the temperature on Serial Monitor
      Serial.print(F("#"));
      Serial.print(i);
      Serial.print(F(": "));
      Serial.print(temperature);
      Serial.println(F(" 'C"));
      
      if (temperature == -273.15)
        {
          Serial.print("Czujnik ");
          Serial.print(i);
          Serial.println(" jest niepodlaczony");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Czujnik ");
          lcd.print(i);
          lcd.setCursor(0,1);
          lcd.print(" jest niegotowy");
          if ( i == 0)
          {
            Term0OK= false;
            }
            
          if ( i == 1)
          {
            Term1OK=false;
            }
            delay(2000);
            lcd.clear();


          
        }
      else
        {
          Serial.print("Czujnik ");
          Serial.print(i);
          Serial.println(" jest gotowy");
             lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Czujnik ");
          lcd.print(i);
          lcd.setCursor(0,1);
          lcd.print(" jest gotowy");
          delay(2000);
          lcd.clear();
        }

     
    }

/////////////////////////////////////////////

//////////// BUZZER ////////////////////////
lcd.setCursor(0,0);
  lcd.print("Test");
  lcd.setCursor(0,1);
  lcd.print("alarmu");
  delay(1000);

pinMode(8, OUTPUT);  

   /* tone(8,LA3,Q); // muzyczka na init
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
    */
    digitalWrite(8, HIGH);
   
  delay(1000);
  lcd.clear();

////////////////////////////////////////////

//////////// WYSWIETLACZ ////////////////////
  lcd.setCursor(0,0);
  lcd.print("Panoramiksie"); // to trzeba dac na koniec setupu
  lcd.setCursor(0,1);
  lcd.print("garnek gotowy");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Szczyt0:");
  lcd.setCursor(0,1);
  lcd.print("Kociol1:");
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

//////////// TERMOMETRY DS1820B /////////////
if (temperature<tempAlarm) {
if (sensors.available())
  {
    for (byte i=0; i<SENSORS_NUM; i++)
    {
      // Odczyt temperatury z sensorow

      temperature = sensors.readTemperature(FA(sensorsAddress[i]));

      // Wyswietlenie wyniku na serial porcie
      Serial.print(F("#"));
      Serial.print(i);
      Serial.print(F(": "));
      Serial.print(temperature);
      Serial.println(F(" 'C"));
      if ( (i == 0) && (Term0OK== true) )
          {
          lcd.setCursor(9,0);
          lcd.print(temperature);
            }
            
          if (  (i == 1) && (Term1OK== true))
          {
       
          lcd.setCursor(9,1);
          lcd.print(temperature);
            }

            
         if ( (i == 0) && (Term0OK== false) )
          {
          lcd.setCursor(0,0);
          lcd.print("                ");
          }

        if ( (i == 1) && (Term1OK== false) )
          {
          lcd.setCursor(0,1);
          lcd.print("                ");
          }
        }
           

    // Wyslanie prosby o nastepny pomiar
    sensors.request();
    
    delay(500);
    
  }}


/////////////////////////////////////////////


//////////// ALARM ////////////////////////
if ( temperature>tempAlarm) 

{
    sensors.request();
   delay(100);
   for (byte i=0; i<SENSORS_NUM; i++)
    {
  temperature = sensors.readTemperature(FA(sensorsAddress[i]));
  Alarm();
}}

////////////////////////////////////////////
if ( temperature==tempAlarm) 

{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Szczyt0:");
  lcd.setCursor(0,1);
  lcd.print("Kociol1:");
    lcd.setCursor(15,0);
  lcd.print("C");
  lcd.setCursor(15,1);
  lcd.print("C");
  lcd.setCursor(14,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(14,1);
  lcd.write((uint8_t)0);
  sensors.request();
  delay(100);
   for (byte i=0; i<SENSORS_NUM; i++)
    {
  temperature = sensors.readTemperature(FA(sensorsAddress[i]));
    }
  
  
}


}



//////////////////Funkcje//////////////////


//////////// FUNKCA  ALARM ////////////////////////
void Alarm ()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" ALARM !!! ");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("Wylacz palnik");
  

  int al;
for( al = 1; al <= 10; al++ )
{
  /*
  tone(8, 4300); //Wygeneruj sygnał o częstotliwości 4300Hz na pinie 8  
  delay(150);  
  tone(8, 3500); //Wygeneruj sygnał o częstotliwości 3500Hz na pinie 8  
  delay(150);
  */
  
  
}
}
////////////////////////////////////////////

////////////////////////////////////////////
