#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX pins for RS485 communication

const int buttonPin = 7;      // Button on the slave to toggle master output
const int slaveOutputPin = 9; // Output pin on the slave to be toggled by master
const int DE_PIN = 11;        // Connect DE to digital pin 11
const int RE_PIN = 12;        // Connect RE to digital pin 12
int slaveNumber = 1;          // Set the slave number for this specific slave

void setup()
{
    Serial.begin(9600);
    mySerial.begin(9600);
    pinMode(DE_PIN, OUTPUT);
    pinMode(RE_PIN, OUTPUT);
    digitalWrite(DE_PIN, HIGH);
    digitalWrite(RE_PIN, HIGH);

    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(slaveOutputPin, OUTPUT);
    digitalWrite(slaveOutputPin, LOW);
}

void loop()
{
    if (digitalRead(buttonPin) == LOW)
    {
        sendToMaster(slaveNumber);
        Serial.print("sending to slaveNumber: ");
        Serial.println(slaveNumber);
        delay(1000); // Debounce delay
    }
}

void sendToMaster(int slaveNumber)
{
    mySerial.write('0' + slaveNumber); // Convert slave number to char and send it
}
