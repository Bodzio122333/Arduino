int PinPomiarowy=A0;
int wartosc_napiecia=0;
int mniejsze=2;
int wieksze=3;

void setup() {
  Serial.begin(9600);
pinMode(mniejsze,OUTPUT);
pinMode(wieksze,OUTPUT);  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
wartosc_napiecia=analogRead(PinPomiarowy);
Serial.print("Odczyt= ");
Serial.println(wartosc_napiecia,DEC);
delay(10);
if (wartosc_napiecia<=512){
  digitalWrite(mniejsze,LOW);
  digitalWrite(wieksze,HIGH);
  }
  else {
    digitalWrite(mniejsze,HIGH);
    digitalWrite(wieksze,LOW);
    }
}

