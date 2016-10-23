#define IP "184.106.153.149" // thingspeak.com
String API = "3NQEALXD084BWSTJ"; //klucz teamspeak
String GET = "GET https://api.thingspeak.com/update?api_key="+API+"&field1=10000";

void setup() {
  Serial.begin(9600);
  if (wifi_connect("Necik", "bodnar5732436")) Serial.println("Polaczono!"); //polaczenie z siecia
  else Serial.println("Brak");


  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  wifi.println(cmd);
  delay(1000);
  if(wifi.find("Error")){
  Serial.println("AT+CIPSTART error");}
  String cmd2 = GET;
  cmd ="AT+CIPSEND=";
  //cmd += String(cmd2.length());
  cmd += String(76);
    delay(5000);
  wifi.println(cmd);
  //if(wifi.find(">")){
  delay(5000);
  wifi.println(cmd2);
  Serial.println(cmd2);
   Serial.println(cmd);
// }
   if(wifi.find("SEND OK")){
  Serial.println("wyslano");
  }
  Serial.println("koniec");

}

void loop() {
  // put your main code here, to run repeatedly:

}



