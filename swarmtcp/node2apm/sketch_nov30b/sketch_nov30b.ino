#include <ESP8266WiFi.h>


const unsigned int port = 9991;//destination-port

WiFiServer server(port);
WiFiClient tcpclient;

//initial setup for wifi-connection
const char* ssid     = "ROOM 367";
const char* password = "itsnotfree";










void setup() {
  Serial.begin(115200);
  
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
/******************************wait till connection is estaiblished***************/  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
//*********************************************************//

 
  server.begin();

  tcpclient = server.available();

  while(!tcpclient)
  {
    tcpclient = server.available();
    delay(2);  
  }

  
  
  
}

void loop() {
  
  
  if(tcpclient.available())
  {
    byte d = tcpclient.read();
    Serial.write(d);
    tcpclient.write(49);  
  }
  
  delay(2);
  
}

