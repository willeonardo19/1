/*
URL del ejercicio
*/

const int ledPin = 12;

int ledState = LOW;  // ledState used to set the LED

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
}
