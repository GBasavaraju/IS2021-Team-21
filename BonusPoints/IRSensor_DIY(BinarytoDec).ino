#include <Servo.h>
const int irLEDPin = 14;
const int irReceiverPin = A0;
unsigned long baseSignal, rawSignal;
unsigned int proximity;
int servoPin = 2;
const int led = 4;
String code = "";
int count = 0;
Servo Servo1;
void setup()   {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(irLEDPin, OUTPUT);
  pinMode(led, OUTPUT);
  Servo1.attach(servoPin, 430, 2400);
}
void loop(){
 NextCode:
    while (count < 4)
    {
        baseSignal = 0;
        rawSignal = 0;
        delay(1000);
        for (int i = 0; i < 50; i++)
        {
            baseSignal += analogRead(irReceiverPin);
            delayMicroseconds(500);
        }
        baseSignal /= 50;
        //  Serial.print("Ambient IR Light: "); Serial.print(baseSignal);

        digitalWrite(irLEDPin, HIGH);
        for (int i = 0; i < 50; i++)
        {
            rawSignal += analogRead(irReceiverPin);
            delayMicroseconds(500);
        }
        rawSignal /= 50;
//          Serial.print("   Raw Signal: "); Serial.print(rawSignal);
        proximity = baseSignal - rawSignal;
//          Serial.print("   Proximity: "); Serial.println(proximity);
        digitalWrite(irLEDPin, LOW);
        if (proximity > 150)
        {
            digitalWrite(led, HIGH);
            code += '1';
//                        Serial.print("Object detected \n");
        }
        else
        {
            digitalWrite(led, LOW);
            code += '0';
//                        Serial.print("No Object detected \n");
        }

        count++;

        while (count == 4)
        {
            Serial.print("\n");
            Serial.print(code);
            convertor();
            break;
        }
        yield();
    }
}
void convertor()
{
    int num = code.toInt();
    int dec = 0;
    int base = 1;
    int temp = num;
    while (temp)
    {
        int lastDigit = temp % 10;
        temp = temp / 10;
        dec += lastDigit * base;
        base = base * 2;
    }
    Serial.print("\n");
    Serial.print("Decimal Value: ");
    Serial.print(dec);
    rotateServo(dec);
    code = "";
    count = 0;
}
void rotateServo(int x)
{
    switch (x)
    {
    case 0:
        Servo1.write(0);
        delay(1000);
        break;
    case 1:
        Servo1.write(18);
        delay(1000);
        break;
    case 2:
        Servo1.write(36);
        delay(1000);
        break;
    case 3:
        Servo1.write(54);
        delay(1000);
        break;
    case 4:
        Servo1.write(72);
        delay(1000);
        break;
    case 5:
        Servo1.write(90);
        delay(1000);
        break;
    case 6:
        Servo1.write(108);
        delay(1000);

        break;
    case 7:
        Servo1.write(126);
        delay(1000);

        break;
    case 8:
        Servo1.write(144);
        delay(1000);

        break;
    case 9:
        Servo1.write(162);
        delay(1000);

        break;
    case 10:
        Servo1.write(18);
        delay(1000);
        Servo1.write(0);
        break;
    case 11:
        Servo1.write(18);
        delay(1000);
        Servo1.write(18);
        break;
    case 12:
        Servo1.write(18);
        delay(1000);
        Servo1.write(36);
        break;
    case 13:
        Servo1.write(18);
        delay(1000);
        Servo1.write(54);
        break;
    case 14:
        Servo1.write(18);
        delay(1000);
        Servo1.write(72);
        break;
    case 15:
        Servo1.write(18);
        delay(1000);
        Servo1.write(90);
        break;
    default:
        Servo1.write(180);
        break;
    }
}
