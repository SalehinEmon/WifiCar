#include <ESP8266WiFi.h>

#include "html_page_data.h"
#include "motor_driver.h"


const char* ssid = ""; //Wifi ssid name
const char* password = ""; // Wifi Password

WiFiServer server(80);

MotorDriver driverOne(D0,D1,D2,D3,D5,D6);

void setup() 
{

  
   Serial.begin(115200);

   pinMode(D4,OUTPUT);


  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();  // Starts the Server
  Serial.println("Server started");

  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() 
{
  digitalWrite(D4,LOW);
//driverOne.Front();
  
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }


    Serial.println("Waiting for new client");
  while (!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

    if (request.indexOf("/up") != -1)
    {
       driverOne.Front();

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");
       client.println("Front");
       return;
      
//      digitalWrite(D1,LOW);
//      digitalWrite(D2,HIGH);
//
//      digitalWrite(D3,HIGH);
//      digitalWrite(D4,LOW);
      
    }
    else if(request.indexOf("/left") != -1)
    {
       driverOne.Right();

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");
       client.println("Left");
       return;
    }
     else if(request.indexOf("/right") != -1)
    {
      
      driverOne.Left();

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");

      client.println("Right");
      return;
    }
     else if(request.indexOf("/back") != -1)
    {
       driverOne.Back();

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");
       client.println("Back");
       return;
    }

    if(request.indexOf("/test") != -1)
    {

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");
       client.println("esp8266ok");
       return ;
    }
    
    if(request.indexOf("/stop") != -1)
    {
      driverOne.StopMov(); 

       client.println("HTTP/1.1 200 OK"); 
       client.println("Content-Type: text/html");
       client.println("");
       client.println("Stop");
       return ;
    }
//-----------html page----------
  client.println("HTTP/1.1 200 OK"); // standalone web server with an ESP8266
  client.println("Content-Type: text/html");
  client.println("");

  client.println(html);

  digitalWrite(D4,HIGH);
  

}
