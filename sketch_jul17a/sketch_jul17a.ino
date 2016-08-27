int syganal_z_czujnika = 8;
int sygnal_prz = 12;
int czas_wlaczenie_lampy = 10000;
void setup() {
  // put your setup code here, to run once:
pinMode(syganal_z_czujnika,INPUT);
pinMode(sygnal_prz,OUTPUT); 


}

void loop() {
if (syganal_z_czujnika = LOW) digitalWrite(sygnal_prz, HIGH);
if (syganal_z_czujnika = HIGH) digitalWrite(sygnal_prz, LOW);
}


