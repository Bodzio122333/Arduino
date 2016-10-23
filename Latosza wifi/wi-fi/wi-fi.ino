#include <SoftwareSerial.h>
SoftwareSerial wifi(10, 11);

boolean wifi_connect(String ssid, String haslo) {
  wifi.begin(9600);
  wifi_status("AT+RST", 2000);
  wifi_status("AT+CIPMUX=0", 2000);
  wifi_status("AT+CWMODE=1", 2000);
  wifi_status("AT+CWDHCP=1,1", 2000);
  delay(5000);
  
  if (wifi_status("AT+CWJAP=\"" + ssid + "\",\"" + haslo + "\"", 5000)) return 1;
  return 0;
}

boolean wifi_status(String wiadomosc, int czas) {
  wifi.println(wiadomosc);
  delay(czas);
  while (wifi.available() > 0)
  {
    if (wifi.find('OK')) return 1;
  }
  return 0;
}

