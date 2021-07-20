#include <Servo.h>
int inputPin = 4;
int servoPin = 2;
String code = "";
unsigned long pressDuration;
unsigned long pressedTime = 0;  //when button is pressed
unsigned long releasedTime = 0; //when button is released
Servo Servo1;
void setup()
{
    Serial.begin(9600);
    pinMode(inputPin, INPUT_PULLUP);
    Servo1.attach(servoPin, 430, 2400);
}

void loop()
{
NextMorse:
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
        code += readMorse();
    }
    while ((millis() - releasedTime) < 500)
    {
        if (digitalRead(inputPin) == LOW)
        {
            goto NextMorse;
        }
        yield();
    }
    convertorToHex();
}

char readMorse()
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

void convertorToHex()
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
        while (letters[i] != "E" || numbers[i] != "E" || specialChar[i] != "E") //loop for comparing input code with letters or Numbers array or Special Characters
        {
            if (letters[i] == code)   //for Ascii char A-Z
            {
                charForHex = char('A' + i);
                Serial.print(char('A' + i));
                rotServoAplha(charForHex);
                break;
            }
            else if (numbers[i] == code)  //for Ascii char 0-9
            {
                numForHex = int(0 + i);
                Serial.print(int(0 + i));
                rotServoNum(numForHex);
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
            Serial.println("Error: Wrong input"); //if input code doesn't match any letter, error
        }
    }
    code = ""; //reset code to blank string
}

void rotServoAplha(char x)
{
    switch (x)
    {
    case 'A':
        Servo1.write(45);
        delay(1000);
        Servo1.write(11.25);
        break;
    case 'B':
        Servo1.write(45);
        delay(1000);
        Servo1.write(22.5);
        break;
    case 'C':
        Servo1.write(45);
        delay(1000);
        Servo1.write(33.75);
        break;
    case 'D':
        Servo1.write(45);
        delay(1000);
        Servo1.write(45);

        break;
    case 'E':
        Servo1.write(45);
        delay(1000);
        Servo1.write(56.25);

        break;
    case 'F':
        Servo1.write(45);
        delay(1000);
        Servo1.write(67.5);

        break;
    case 'G':
        Servo1.write(45);
        delay(1000);
        Servo1.write(78.75);

        break;
    case 'H':
        Servo1.write(45);
        delay(1000);
        Servo1.write(90);

        break;
    case 'I':
        Servo1.write(45);
        delay(1000);
        Servo1.write(101.25);

        break;
    case 'J':
        Servo1.write(45);
        delay(1000);
        Servo1.write(112.5);

        break;
    case 'K':
        Servo1.write(45);
        delay(1000);
        Servo1.write(123.75);

        break;
    case 'L':
        Servo1.write(45);
        delay(1000);
        Servo1.write(135);

        break;
    case 'M':
        Servo1.write(45);
        delay(1000);
        Servo1.write(146.25);

        break;
    case 'N':
        Servo1.write(45);
        delay(1000);
        Servo1.write(157.5);

        break;
    case 'O':
        Servo1.write(45);
        delay(1000);
        Servo1.write(168.75);

        break;
    case 'P':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(0);

        break;
    case 'Q':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(11.25);

        break;
    case 'R':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(22.5);

        break;
    case 'S':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(33.75);

        break;
    case 'T':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(45);

        break;
    case 'U':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(56.25);

        break;
    case 'V':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(67.5);

        break;
    case 'W':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(78.75);

        break;
    case 'X':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(90);

        break;
    case 'Y':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(101.25);

        break;
    case 'Z':
        Servo1.write(56.25);
        delay(1000);
        Servo1.write(112.75);

        break;
    default:
        Servo1.write(180);
    }
}
void rotServoNum(int y)
{
    switch (y)
    {
    case 0:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(0);

        break;
    case 1:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(11.25);

        break;
    case 2:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(22.5);

        break;
    case 3:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(33.75);

        break;
    case 4:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(45);

        break;
    case 5:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(56.25);

        break;
    case 6:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(67.5);

        break;
    case 7:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(78.75);

        break;
    case 8:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(90);

        break;
    case 9:
        Servo1.write(33.75);
        delay(1000);
        Servo1.write(101.25);

        break;
    default:
        Servo1.write(180);
        break;
    }
}
