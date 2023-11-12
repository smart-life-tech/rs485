#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX pins for RS485 communication

const int numSlaves = 7;
const int numMasterButtons = 7;
const int DE_PIN = 9;  // Connect DE to digital pin 9
const int RE_PIN = 10; // Connect RE to digital pin 10
enum SlavePins
{
    Slave1 = 22,
    Slave2 = 24,
    Slave3 = 26,
    Slave4 = 28,
    Slave5 = 30,
    Slave6 = 32,
    Slave7 = 34
};

enum MasterButtons
{
    Button1 = 40,
    Button2 = 42,
    Button3 = 44,
    Button4 = 46,
    Button5 = 48,
    Button6 = 50,
    Button7 = 52
};

void setup()
{
    Serial.begin(9600);
    mySerial.begin(9600);
    pinMode(DE_PIN, OUTPUT);
    pinMode(RE_PIN, OUTPUT);
    digitalWrite(DE_PIN, HIGH);
    digitalWrite(RE_PIN, HIGH);
    for (int i = 0; i < numSlaves; i++)
    {
        pinMode(static_cast<SlavePins>(Slave1 + i), OUTPUT);
        digitalWrite(static_cast<SlavePins>(Slave1 + i), LOW);
    }

    for (int i = 0; i < numMasterButtons; i++)
    {
        pinMode(static_cast<MasterButtons>(Button1 + i), INPUT_PULLUP);
    }
}

void loop()
{
    for (int i = 0; i < numMasterButtons; i++)
    {
        if (digitalRead(static_cast<MasterButtons>(Button1 + i)) == LOW)
        {
            toggleSlavePin(i + 1); // Toggle the corresponding slave pin
            delay(1000);           // Debounce delay
        }
    }

    if (mySerial.available())
    {
        char data = mySerial.read();
        int slaveNumber = data - '0'; // Convert char to integer

        if (isValidSlaveNumber(slaveNumber))
        {
            Serial.print("commnad received from slaveNumber: ");
            Serial.println(slaveNumber);
            toggleSlavePin(slaveNumber);
        }
    }
}

bool isValidSlaveNumber(int slaveNumber)
{
    return (slaveNumber >= 1 && slaveNumber <= numSlaves);
}

void toggleSlavePin(int slaveNumber)
{
    int pinIndex = slaveNumber - 1;
    digitalWrite(static_cast<SlavePins>(Slave1 + pinIndex), !digitalRead(static_cast<SlavePins>(Slave1 + pinIndex))); // Toggle the corresponding pin
}
