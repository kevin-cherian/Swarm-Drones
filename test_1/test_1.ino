#include <ESP8266WiFi.h>

int buffer_count = 0;
String buffer_string = "";

const unsigned int server_port = 9991;//destination-port

WiFiServer server(server_port);
WiFiClient Vtcpclient;

//initial setup for wifi-connection
const char* ssid     = "ROOM 367";
const char* password = "itsnotfree";




const char* ip = "192.168.0.5";//destination-ip
unsigned int port = 9976;//destination-port

#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 15);

void setup() {
  Serial.begin(57600);
  mySerial.begin(9600);
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
  Vtcpclient = server.available();

  while(!Vtcpclient)
  {
    Vtcpclient = server.available();
    delay(2);  
  }

  
  Serial.println("...client connected....");
}

void loop() {
  
  
 if(mySerial.available())
 {
  while(mySerial.available())
    {
    byte data  = mySerial.read();
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
 }
  
  
 if(Vtcpclient.available())
  {
    byte d = Vtcpclient.read();
    Vtcpclient.write(49);
    mySerial.write(d);
    
      
  }
  
  delay(4);
   
  
 
  
  
}

