#include <ESP8266WiFi.h>

const char *ssid = "NotMe";
const char *password = "GB";

String codeVal = ""; // value read from the user
String outputValue = ""; // value sent to server

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.begin(115200);
}

void loop()
{
    // read the morsecode
    codeVal = ".-";
    outputValue = convertor();

    // print the results to the Serial Monitor:
    Serial.print("Code = ");
    Serial.print(codeVal);
    Serial.print("\t output = ");
    Serial.println(outputValue);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const char *host = "192.168.4.1";
    const int httpPort = 80;

    if (!client.connect(host, httpPort))
    {
        Serial.println("connection failed");
        return;
    }

    // We now create a URI for the request
    String url = "/data/";
    url += "?codeVal=";
    url += outputValue;

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    Serial.println();
    Serial.println("Closing connection");
    Serial.println();
    Serial.println();
    Serial.println();

    delay(500);
}

String convertor()
{
    static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                               ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"};
    static String numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....",
                               "-....", "--...", "---..", "----.", "E"};
    int i = 0;
    char charForHex;
    int numForHex;
    String hex = "";
    if (codeVal == ".-.-.-")
    {
        Serial.print("."); //for break
    }
    else
    {
        while (letters[i] != "E" || numbers[i] != "E") //loop for comparing input code with letters or Numbers array
        {
            if (letters[i] == codeVal)
            {
                charForHex = char('A' + i);
                hex = HexAlpha(charForHex);
                break;
            }
            else if (numbers[i] == codeVal)
            {
                numForHex = int(0 + i);
                hex = HexNum(numForHex);
                break;
            }
            i++;
        }
        if (letters[i] == "E" || numbers[i] == "E")
        {
            Serial.println("<Wrong input>"); //if input code doesn't match any letter, error
        }
    }
    return hex;
}

String HexAlpha(char y)
{
    String hex;
    switch (y)
    {
    case 'A':
        hex = "41";
        break;
    case 'B':
        hex = "42";
        break;
    case 'C':
        hex = "43";
        break;
    case 'D':
        hex = "44";
        break;
    case 'E':
        hex = "45";
        break;
    case 'F':
        hex = "46";
        break;
    case 'G':
        hex = "47";
        break;
    case 'H':
        hex = "48";
        break;
    case 'I':
        hex = "49";
        break;
    case 'J':
        hex = "4A";
        break;
    case 'K':
        hex = "4B";
        break;
    case 'L':
        hex = "4C";
        break;
    case 'M':
        hex = "4D";
        break;
    case 'N':
        hex = "4E";
        break;
    case 'O':
        hex = "4F";
        break;
    case 'P':
        hex = "50";
        break;
    case 'Q':
        hex = "51";
        break;
    case 'R':
        hex = "52";
        break;
    case 'S':
        hex = "53";
        break;
    case 'T':
        hex = "54";
        break;
    case 'U':
        hex = "55";
        break;
    case 'V':
        hex = "56";
        break;
    case 'W':
        hex = "57";
        break;
    case 'X':
        hex = "58";
        break;
    case 'Y':
        hex = "59";
        break;
    case 'Z':
        hex = "5A";
        break;
    }
    return hex;
}
String HexNum(int w)
{
    String hex;
    switch (w)
    {
    case 0:
        hex = "30";
        break;
    case 1:
        hex = "31";
        break;
    case 2:
        hex = "32";
        break;
    case 3:
        hex = "33";
        break;
    case 4:
        hex = "34";
        break;
    case 5:
        hex = "35";
        break;
    case 6:
        hex = "36";
        break;
    case 7:
        hex = "37";
        break;
    case 8:
        hex = "38";
        break;
    case 9:
        hex = "39";
        break;
    }
    return hex;
}
