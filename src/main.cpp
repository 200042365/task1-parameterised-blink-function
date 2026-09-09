#include <Arduino.h>

const int blue = 13;
const int white = 14;

// Function to blink an LED on a given pin
// pin: which GPIO pin to control
// times: how many blink cycles to do
// onTime: how long the LED stays ON (and also how long it stays OFF, since delay(onTime) is used twice)
void blink_led(int pin, int times, int onTime) {
  for  (int x = 0; x < times; x++) {  // repeat blink sequence "times" times
    digitalWrite(pin, HIGH);
    delay(onTime);    // wait onTime milliseconds 
    digitalWrite(pin, LOW);
    delay(onTime);    // wait onTime milliseconds (creates equal ON/OFF timing)
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);

// These are local variables inside setup(), and are not used elsewhere
  int urgentPin = blue;     // assigns urgentPin the same value as blue
  int routinePin = white;   // assigns routinePin the same value as white
// Note: urgentPin and routinePin go out of scope after setup() ends.
}

void loop() {
// These are local variables inside loop(), recreated every time loop() runs.  
  int urgentPin = blue;      // urgent pin is blue (pin 13)
  int routinePin = white;   // routine pin is white (pin 14)

  blink_led(urgentPin, 5, 100);
// Blink LED: 5 times, ON/OFF duration = ms
  blink_led(routinePin, 5, 300);
}

