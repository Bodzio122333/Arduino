// Program odczytuje temperaturę z czujnika

#include <OneWire.h>
#include <DS18B20.h>

static int dioda = 1;

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 16

// Adres czujnika
byte address[8] = {0x28, 0x3C, 0x8B, 0x3, 0x0, 0x0, 0x80, 0x31

};

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  pinMode(dioda, OUTPUT);
  while(!Serial);
  Serial.begin(9600);

  sensors.begin(16);
  sensors.request(address);
 
}

void temp_dioda(float temp){
 if (temp >= 27)
{
   digitalWrite(dioda, 0); 
}else digitalWrite(dioda, 1);   
}


void loop() {
  if (sensors.available())
  {
    float temperature = sensors.readTemperature(address);

    Serial.print(temperature);
    Serial.println(" 'C");
    temp_dioda(temperature);

    sensors.request(address);
  }
delay (1000);
  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania

}
