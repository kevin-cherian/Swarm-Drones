#include <ESP8266WiFi.h>

int buffer_count = 0;
String buffer_string = "";



//initial setup for wifi-connection
const char* ssid     = "ROOM 367";
const char* password = "itsnotfree";




const char* ip = "192.168.0.5";//destination-ip
unsigned int port = 9997;//destination-port




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
  
  
 if(Serial.available())
 {
  while(Serial.available())
    {
    byte data  = Serial.read();
    buffer_string += String(int(data))+" ";
    buffer_count++;
    }
 }

 if(buffer_count >= 200)
 {
  
    WiFiClient tcpclient;
    while(!tcpclient.connect(ip,port))
    { 
        delay(2);
    }  

    tcpclient.print(buffer_string);
    buffer_string = "";
    buffer_count = 0;

    while(tcpclient.available())
        char c = tcpclient.read();
  
    tcpclient.stop();
  
  
    delay(4);
   
 } 
 
  
  
}

