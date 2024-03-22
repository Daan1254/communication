////////////////////////////////////////////////////////////////////////////////
//
// The code below can be used as an example for communication between the Arduino
// and the Serial Monitor or a C# application.
// Search for "TODO" and fill in the code to implement your message handling.
//
////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>

const int ledPin = 6;
String message; // String to store incoming messages from the serial port.


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // To receive messages from the serial port (USB cable) the incoming characters are read one by one and put into a string.
  // It is assumed that each message ends with a newline character ('\n') to indicate the end of the message.
  // IMPORTANT NOTE 1: In the Serial Monitor or C# application, use the same communication speed as set above, so 9600 baud.
  // IMPORTANT NOTE 2: Make sure the string sent from the other side ends with a single newline character ('\n').
}


void loop() {
  if (Serial.available() > 0)
  {
    char received = Serial.read();

    if (received == '\n') // Message is finished, so process message.
    {
      // TODO: Below fill in your own message handling.

      int number = message.toInt();
      
      if (!isnan(number) && number != 0) {
        Serial.println(String((number * number)));
      } else {
        Serial.println("invalid number");
      }
      message = ""; // Message is processed, so clear message.
    }
    else  // Message is not finished yet, so add the received character to message.
    {
      message += received;
    }
  }
}
