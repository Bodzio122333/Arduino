#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

/* RST          9
   SDA(SS)      10
   MOSI         11 / ICSP-4
   MISO         12 / ICSP-1
   SCK          13 / ICSP-3*/
#include <SPI.h> //zmienne do RFID
#include <MFRC522.h>
#define SS_PIN 7
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4; //RFID koniec

LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int zalogowany = 0;

#define pin_R 10
#define pin_G 5
#define pin_B 6
#define pin_przekaznik 8
//zmienne
int czerwony = 255;
int czerwony_skala = 0;
int zielony = 255;
int zielony_skala = 0;
int niebieski = 255;
int niebieski_skala = 0;
bool przekaznik = 0;
bool zmiana = 0;
byte plamka[8] = {24, 28, 30, 31, 31, 30, 28, 24};

int opcja = 1;


/*CLK pin 4,
  DT  pin 3
  SW  pin 2*/
void zlicz() {
  if (zalogowany == 1) {
    zmiana = 1;
    if (!digitalRead(4)) {
      switch (opcja) {
        case 1: czerwony -= 10; break;
        case 2: zielony -= 10; break;
        case 3: niebieski -= 10; break;
        case 4: przekaznik = 1; break;
      }
    }
    else {
      switch (opcja) {
        case 1: czerwony += 10; break;
        case 2: zielony += 10; break;
        case 3: niebieski += 10; break;
        case 4: przekaznik = 0; break;
      }
    }
  }
  delay(50);
}

void zeruj() {
  if (opcja >= 4) opcja = 1; else opcja++;
  zmiana = 1;
  delay(100);
}

void wystawienie_wyjsc() {
  if (czerwony > 255) czerwony = 255;
  if (czerwony < 0) czerwony = 0;
  if (zielony > 255) zielony = 255;
  if (zielony < 0) zielony = 0;
  if (niebieski > 255) niebieski = 255;
  if (niebieski < 0) niebieski = 0;
  analogWrite(pin_R, czerwony);
  analogWrite(pin_G, zielony);
  analogWrite(pin_B, niebieski);
  digitalWrite(pin_przekaznik, przekaznik);
}

void setup() {
  pinMode(pin_przekaznik, OUTPUT);
  wystawienie_wyjsc();
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), zlicz, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), zeruj, FALLING);
  lcd.begin (16, 2);
  lcd.backlight();
  lcd.createChar(1, plamka);
  lcd.clear();
  lcd.home ();
}

void legitymacja() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nie baw sie ");
  lcd.setCursor(0, 1);
  lcd.print("legitymacja!");
  delay(2000);
  zaloguj();
}

void wyswietlacz() {
  czerwony_skala = map(czerwony, 0, 255, 255, 0);
  zielony_skala = map(zielony, 0, 255, 255, 0);
  niebieski_skala = map(niebieski, 0, 255, 255, 0);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("R");
  lcd.print(czerwony_skala);
  lcd.setCursor(6, 0);
  lcd.print("G");
  lcd.print(zielony_skala);
  lcd.setCursor(11, 0);
  lcd.print("B");
  lcd.print(niebieski_skala);
  lcd.setCursor(1, 1);
  lcd.print("Przekaznik: ");
  if (przekaznik == 1) lcd.print("Wl"); else lcd.print("Wyl");

  switch (opcja) {
    case 1: lcd.setCursor(0, 0);  break;
    case 2: lcd.setCursor(5, 0);  break;
    case 3: lcd.setCursor(10, 0); break;
    case 4: lcd.setCursor(0, 1);  break;
  }
  lcd.write(1);
}

void zaloguj() {
  lcd.setCursor(0, 0);
  lcd.print("Brak dostepu");
  lcd.setCursor(0, 1);
  lcd.print("Zbliz karte");
  while (zalogowany == 0) {
    if (mfrc522.PICC_IsNewCardPresent()) {
      if (mfrc522.PICC_ReadCardSerial()) {
        serNum0 = mfrc522.uid.uidByte[0];
        serNum1 = mfrc522.uid.uidByte[1];
        serNum2 = mfrc522.uid.uidByte[2];
        serNum3 = mfrc522.uid.uidByte[3];
        if (serNum0 == 118
            && serNum1 == 246
            && serNum2 == 125
            && serNum3 == 65) {
          zalogowany = 1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Zalogowany:");
          lcd.setCursor(0, 1);
          lcd.print("Karta 1");
        }
        if (serNum0 == 210
            && serNum1 == 116
            && serNum2 == 29
            && serNum3 == 43) {
          zalogowany = 1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Zalogowany:");
          lcd.setCursor(0, 1);
          lcd.print("Karta 2");
        }
        if (serNum0 == 186
            && serNum1 == 52
            && serNum2 == 95
            && serNum3 == 55
            && serNum4 == 230) {
          legitymacja();
        }
      }
       mfrc522.PICC_HaltA();
    }
  }
  delay(2000);
  wyswietlacz();
}


void loop() {
  if (zalogowany != 1)  zaloguj();
  if (zmiana == 1) {
    zmiana = 0;
    wystawienie_wyjsc();
    wyswietlacz();
  }
}
