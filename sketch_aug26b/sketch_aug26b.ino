#include <Wire.h>
#include <DS1307RTC.h>
 
//DS1307 clock;
//RTCDateTime dt;
 
void setup()
{
  Serial.begin(9600);
 
  // Inicjalizacja DS1307
  Serial.println("Inicjalizacja DS1307");;
  clock.begin();
 
  // Jeśli nie ustawiono daty, ustawiamy
  if (!clock.isReady())
  {
    // Data i czas z momentu kompilacji
    clock.setDateTime(__DATE__, __TIME__);
  }
}
 
void loop()
{
  dt = clock.getDateTime();
 
  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
 
  delay(1000);
}
