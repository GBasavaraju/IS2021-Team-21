#include <SPI.h>
#include <ESP8266WiFi.h>


char ssid[] = "NoTaVaILabLe";               // SSID of your home WiFi
char pass[] = "41082485";                           // password of your home WiFi
WiFiServer server(80);                    

IPAddress ip(192, 168, 0, 80);            // IP address of the server
IPAddress gateway(192,168,0,1);           // gateway of your network
IPAddress subnet(255,255,255,0);          // subnet mask of your network

void setup() {
  Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server

}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("Hey Client, I am server.\r"); // sends the answer to the client
    }
    client.stop();                // tarminates the connection with the client
  }
}
