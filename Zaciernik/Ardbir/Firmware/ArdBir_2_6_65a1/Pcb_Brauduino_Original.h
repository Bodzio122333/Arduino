// sensor and lcd
OneWire ds(11);
LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// push buttons
const char Button_up    = A3;
const char Button_dn    = A2;
const char Button_start = A1;
const char Button_enter = A0;

// outputs
const byte Pump = 8;
const byte Buzz = 10;
const byte Heat = 9;

