
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "NotMe";
const char *password = "GB";

ESP8266WebServer server(80);

void handleSentVar()
{
    Serial.println("handleSentVar function called...");
    if (server.hasArg("codeVal"))
    { 
        Serial.println("code received..."); // this is the variable sent from the client
        String readingToPrint = server.arg("codeVal");
        Serial.print("Reading: ");
        Serial.println(readingToPrint);
        Serial.println();
        server.send(200, "text/html", "Data received");
    }
}

void setup()
{
    delay(1000);
    Serial.begin(115200);
    Serial.println();
    Serial.print("Configuring access point...");

    WiFi.softAP(ssid, password);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
    server.handleClient();
}
