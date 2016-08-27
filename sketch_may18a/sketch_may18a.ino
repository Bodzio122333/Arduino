#include <SPI.h> // interfejs SPI dla czytnika
#include <MFRC522.h> //biblioteka dla czytnika
#include <Wire.h> //biblioteka dla LCD
#include <LiquidCrystal_I2C.h> //interfejs I2C dla LCD

#define RST_PIN  9 // sygnał zegarowy
#define SS_PIN 10 // Slave Select - wybór układu podrzędnego, adresu urządzenia
byte readCard[4]; //zmienna przechowująca odczytany numer UID karty
MFRC522 czytnik(SS_PIN, RST_PIN); // Utworzenie instancji czytnika na wybranych pinach
LiquidCrystal_I2C lcd (0x27, 16,2); //Utworzenie instancji ekranu o adresie 0x27 i ilosci znakow 16x2 (16 znaków w dwóch liniach)

void setup() {
  lcd.init (); //inicjalizacja ekranu
  lcd.backlight (); //wlaczenie podwietlenia LCD
  SPI.begin(); // Inicjalizacja interfejsu SPI
  czytnik.PCD_Init(); // Inicjalizacja PCD
  lcd.setCursor(0,0); //ustawienie kursora na początek ekranu
  if(!SprawdzCzytnik())lcd.print("Blad czytnika.");// Sprawdzam polączenie z czytnikiem
  
}
// główna pętla programu
void loop() {
odczytUID();
}

bool SprawdzCzytnik() {
  // Sprawdzam wersje oprogramowania czytnika w rejestrze
  byte v = czytnik.PCD_ReadRegister(czytnik.VersionReg);
  // jeżeli otrzymamy 0x00 lub 0xFF to połączenie z czytnikiem się nie udało
  if ((v == 0x00) || (v == 0xFF)) {
    return false;
  }else return true;
}

int odczytUID() {
  if ( ! czytnik.PICC_IsNewCardPresent()) { //Gdy nie ma karty, przerwij działanie
    return 0;
  }
  if ( ! czytnik.PICC_ReadCardSerial()) {   //Odczytaj numer i kontynuuj, przerwij w przypadku blędu
    return 0;
  }
//odczytuje z karty 4 bajtowe UID
  lcd.setCursor(0,0);
  for (int i = 0; i < 4; i++) { 
    readCard[i] = czytnik.uid.uidByte[i];
    lcd.print(readCard[i], HEX);
  }
  czytnik.PICC_HaltA(); // koniec odczytywania
  return 1;
}
