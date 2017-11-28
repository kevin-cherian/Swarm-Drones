#include <ESP8266WiFi.h>





byte data;// our udp-data packet

//initial setup for wifi-connection
const char* ssid     = "Kevin";
const char* password = "password";




const char* ip = "192.168.43.102";//destination-ip
unsigned int port = 9999;//destination-port




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

 

  

  
}

void loop() {
  
  
  //while(!Serial.available())
    //delay(2);

  //data = Serial.read();

  WiFiClient tcpclient;
  while(!tcpclient.connect(ip,port))
    delay(2);
 
   
  tcpclient.write(49);
  tcpclient.stop();
  delay(2);
  
 
  
  
}

