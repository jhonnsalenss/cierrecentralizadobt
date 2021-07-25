#include <Arduino.h>
#include <SoftwareSerial.h>

#define PIN_RELE1 0x05
#define PIN_RELE2 0x06

SoftwareSerial SerialBT(10,11);  // RX = 10 | TX = 11 ; pines de arduino
char myData;
int myValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_RELE1, OUTPUT);
  pinMode(PIN_RELE2, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(PIN_RELE1, LOW);
  digitalWrite(PIN_RELE2, LOW);
  Serial.begin(9600);
  SerialBT.begin(9600);
  Serial.println("iniciando bluetooth");
//  myData = 0;
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available() > 0) {
    myData = SerialBT.read();
    if (myData == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(PIN_RELE1, HIGH);
      delay(1000);
//      delay(1000);
      digitalWrite(PIN_RELE1, LOW);
//      Serial.println("0");
    } else {
      if (myData == '1')
      {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(PIN_RELE2,HIGH);
        delay(1000);
//        delay(1000);
        digitalWrite(PIN_RELE2,LOW);
//        Serial.println("1");
      }      
    }
//    Serial.write(myData);       // Write in consola received data
  }
/*
  // Send data from consola
  if (Serial.available())
  {
    myData = Serial.read();
    SerialBT.write(myData);
    Serial.print(myData);
  }
*/
}
