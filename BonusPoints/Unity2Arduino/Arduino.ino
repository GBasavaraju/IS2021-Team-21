int data;
const int ledPin =  4; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    data = Serial.read();
    if (data == 'A'){
      digitalWrite(ledPin,HIGH);
      delay(1000);
      }
    else
    digitalWrite(ledPin,LOW);
  }
}
