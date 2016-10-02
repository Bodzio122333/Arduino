#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
LiquidCrystal_I2C lcd(0x27,20,4);
 
dht11 DHT11;
 
#define DHT11PIN 2    //przypisanie pinu 2 Arduino jako odczyt z sensora
 
void setup()
{
  Serial.begin(115200);                    //inicjalizacja monitora szeregowego
  Serial.println("Program testowy DHT11"); 
  Serial.println();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Wilgot: ");
   lcd.setCursor(14,0);
   lcd.print("C");
   lcd.setCursor(14,1);
   lcd.print("%");
}
 
void loop()
{
  int chk = DHT11.read(DHT11PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym
 
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
        Serial.print("OK\t"); 
        break;
    case DHTLIB_ERROR_CHECKSUM: 
        Serial.println("Błąd sumy kontrolnej"); 
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
  lcd.setCursor(8,0);
  lcd.print((float)DHT11.temperature, 2);
  lcd.setCursor(8,1);
  lcd.print((float)DHT11.humidity, 2);
  
  
  
 
  delay(1000);                                  //opóźnienie między kolejnymi odczytami - 1 s
} 
