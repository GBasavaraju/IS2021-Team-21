int inputPin = 4;

String code = "";
unsigned long pressDuration;
unsigned long pressedTime = 0;  //when button is pressed
unsigned long releasedTime = 0; //when button is released

int led1 = 16; //d0
int led2 = 5;  //d1
int led3 = 0;  //d3
int led4 = 2;  //d4
int led5 = 14; //d5
int led6 = 12; //d6
int led7 = 13; //d7

void setup()
{
    Serial.begin(9600);
    pinMode(inputPin, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
}

void loop()
{
NextCode:
    while (digitalRead(inputPin) == HIGH)
    {
        yield();
    }
    pressedTime = millis(); //time at button press

    while (digitalRead(inputPin) == LOW)
    {
        yield();
    }
    releasedTime = millis(); //time at button release

    pressDuration = releasedTime - pressedTime; //time for which button is released

    if (pressDuration > 50)
    { // accomodate debounce
        code += readIO();
    }
    while ((millis() - releasedTime) < 500)
    {
        if (digitalRead(inputPin) == LOW)
        {
            goto NextCode;
        }
        yield();
    }
    convertor();
}

char readIO()
{
    if (pressDuration < 1500 && pressDuration > 100)
    {
        return '.'; //if button press less than 1.5sec, it is a dot
    }
    else if (pressDuration > 1500)
    {
        return '-'; //if button press more than 1.5sec, it is a dash
    }
}

void convertor()
{
    static String specialChar[] = {".......", "E"};
    static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                               ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"};
    static String numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....",
                               "-....", "--...", "---..", "----.", "E"};
    int i = 0;
    char charForHex;
    int numForHex;
    if (code == ".-.-.-")
    {
        Serial.print("."); //for break
    }
    else
    {
        while (letters[i] != "E" || numbers[i] != "E" || specialChar[i] != "E") //loop for comparing input code with letters or Numbers array or special characters
        {
            if (letters[i] == code)
            {
                charForHex = char('A' + i);
                Serial.print(char('A' + i));
                LEDAplha(charForHex);
                break;
            }
            else if (numbers[i] == code)
            {
                numForHex = int(0 + i);
                Serial.print(int(0 + i));
                LEDNum(numForHex);
                break;
            }
            else if (specialChar[i] == code)
            {
                Serial.print(" ");
                break;
            }
            i++;
        }
        if (letters[i] == "E" || numbers[i] == "E")
        {
            Serial.println("<Wrong input>"); //if input code doesn't match any letter, error
        }
    }
    code = ""; //reset code to blank string
}

void LEDAplha(char x)
{
    switch (x)
    {
    case 'A':
        HexaLeds('4');
        delay(3000);
        HexaLeds('1');
        break;
    case 'B':
        HexaLeds('4');
        delay(3000);
        HexaLeds('2');
        break;
    case 'C':
        HexaLeds('4');
        delay(3000);
        HexaLeds('3');
        break;
    case 'D':
        HexaLeds('4');
        delay(3000);
        HexaLeds('4');
        break;
    case 'E':
        HexaLeds('4');
        delay(3000);
        HexaLeds('5');
        break;
    case 'F':
        HexaLeds('4');
        delay(3000);
        HexaLeds('6');
        break;
    case 'G':
        HexaLeds('4');
        delay(3000);
        HexaLeds('7');
        break;
    case 'H':
        HexaLeds('4');
        delay(3000);
        HexaLeds('8');
        break;
    case 'I':
        HexaLeds('4');
        delay(3000);
        HexaLeds('9');
        break;
    case 'J':
        HexaLeds('4');
        delay(3000);
        HexaLeds('A');
        break;
    case 'K':
        HexaLeds('4');
        delay(3000);
        HexaLeds('B');
        break;
    case 'L':
        HexaLeds('4');
        delay(3000);
        HexaLeds('C');
        break;
    case 'M':
        HexaLeds('4');
        delay(3000);
        HexaLeds('D');
        break;
    case 'N':
        HexaLeds('4');
        delay(3000);
        HexaLeds('E');
        break;
    case 'O':
        HexaLeds('4');
        delay(3000);
        HexaLeds('F');
        break;
    case 'P':
        HexaLeds('5');
        delay(3000);
        HexaLeds('0');
        break;
    case 'Q':
        HexaLeds('5');
        delay(3000);
        HexaLeds('1');
        break;
    case 'R':
        HexaLeds('5');
        delay(3000);
        HexaLeds('2');
        break;
    case 'S':
        HexaLeds('5');
        delay(3000);
        HexaLeds('3');
        break;
    case 'T':
        HexaLeds('5');
        delay(3000);
        HexaLeds('4');
        break;
    case 'U':
        HexaLeds('5');
        delay(3000);
        HexaLeds('5');
        break;
    case 'V':
        HexaLeds('5');
        delay(3000);
        HexaLeds('6');
        break;
    case 'W':
        HexaLeds('5');
        delay(3000);
        HexaLeds('7');
        break;
    case 'X':
        HexaLeds('5');
        delay(3000);
        HexaLeds('8');
        break;
    case 'Y':
        HexaLeds('5');
        delay(3000);
        HexaLeds('9');
        break;
    case 'Z':
        HexaLeds('5');
        delay(3000);
        HexaLeds('A');
        break;
    default:
        break;
    }
}
void LEDNum(int y)
{
    switch (y)
    {
    case 0:
        HexaLeds('3');
        delay(3000);
        HexaLeds('0');
        break;
    case 1:
        HexaLeds('3');
        delay(3000);
        HexaLeds('1');
        break;
    case 2:
        HexaLeds('3');
        delay(3000);
        HexaLeds('2');
        break;
    case 3:
        HexaLeds('3');
        delay(3000);
        HexaLeds('3');
        break;
    case 4:
        HexaLeds('3');
        delay(3000);
        HexaLeds('4');
        break;
    case 5:
        HexaLeds('3');
        delay(3000);
        HexaLeds('5');
        break;
    case 6:
        HexaLeds('3');
        delay(3000);
        HexaLeds('6');
        break;
    case 7:
        HexaLeds('3');
        delay(3000);
        HexaLeds('7');
        break;
    case 8:
        HexaLeds('3');
        delay(3000);
        HexaLeds('8');
        break;
    case 9:
        HexaLeds('3');
        delay(3000);
        HexaLeds('9');
        break;
    default:
        delay(3000);
        break;
    }
}
void HexaLeds(char u)
{
    switch (u)
    {
    case '0':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case '1':
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        break;
    case '2':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, HIGH);
        break;
    case '3':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case '4':
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        break;
    case '5':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case '6':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case '7':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        break;
    case '8':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case '9':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, LOW);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        break;
    case 'A':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, LOW);
        break;
    case 'B':
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case 'C':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, HIGH);
        break;
    case 'D':
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, HIGH);
        digitalWrite(led7, HIGH);
        break;
    case 'E':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, HIGH);
        break;
    case 'F':
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        break;
    default:
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        break;
    }
}
