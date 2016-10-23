#define IP "184.106.153.149" // thingspeak.com
String API = "3NQEALXD084BWSTJ"; //klucz teamspeak
String GET = "GET https://api.thingspeak.com/update?api_key="+API+"&field1=20";

void setup() {
  Serial.begin(9600);
  if (wifi_connect("UPCF95A422", "Bjzv2czzrKvk")) Serial.println("Polaczono!"); //polaczenie z siecia
  else Serial.println("Brak");


  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  wifi.println(cmd);
  delay(500);
  if(wifi.find("Error")){
  Serial.println("AT+CIPSTART error");}
  String cmd2 = GET;
  cmd ="AT+CIPSEND=";
  cmd += String(cmd2.length());
  wifi.println(cmd);
  if(wifi.find(">")){
  wifi.print(cmd2);
  Serial.println("wyslano");
  }
  Serial.println("koniec");

}

void loop() {
  // put your main code here, to run repeatedly:

}



