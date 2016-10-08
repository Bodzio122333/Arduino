//////////// WYSWIETLACZ ////////////////////
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // Adres wyświetlacza i jego rozmiar
/////////////////////////////////////////////

//////////// TERMOMETRY DS1820B /////////////
#include <OneWire.h>
#include <DS18B20.h>
const byte ONEWIRE_PIN = 2; //Pin 1-wire do którego jest podłączona szyna danych przez rezystor 4.7 kohm
byte sensorAddress[8] = {0x28, 0xCD, 0x8D, 0x3, 0x0, 0x0, 0x80, 0xE8};

// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);
/////////////////////////////////////////////

//////////// BUZZER ////////////////////////


////////////////////////////////////////////


void setup() {

//////////// TERMOMETRY DS1820B /////////////
  // Serial port setup
  while(!Serial);
  Serial.begin(9600);
  
  // DS18B20 sensors setup
  sensors.begin();


/////////////////////////////////////////////

//////////// WYSWIETLACZ ////////////////////
lcd.init();  // Inicjalizacja LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Inicjalizacja");
  lcd.setCursor(0,1);
  lcd.print("systemu");
  delay(3000);
  lcd.clear();

  
  lcd.print("Psotniku Twoj"); // to trzeba dac na koniec setupu
  lcd.setCursor(0,1);
  lcd.print("garnek gotowy");
  delay(10000);
  lcd.clear();
  



/////////////////////////////////////////////

//////////// BUZZER ////////////////////////


////////////////////////////////////////////
}

void loop() {

//////////// TERMOMETRY DS1820B /////////////
  // Requests sensor for measurement
  sensors.request(sensorAddress);
  
  // Waiting (block the program) for measurement reesults
  while(!sensors.available());
  
  // Reads the temperature from sensor
  float temperature = sensors.readTemperature(sensorAddress);
  
  // Prints the temperature on Serial Monitor
  Serial.print(temperature);
  Serial.println(F(" 'C"));

/////////////////////////////////////////////

//////////// WYSWIETLACZ ////////////////////


/////////////////////////////////////////////

//////////// BUZZER ////////////////////////


////////////////////////////////////////////
}
