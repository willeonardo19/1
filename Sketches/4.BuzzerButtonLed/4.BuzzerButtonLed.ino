/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button

 */

//constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 7;       // the number of the pushbutton pin
const int ledPin = 13;
int pinBuzzer = 6;
// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;                // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT); 
  analogWrite(pinBuzzer, 000);
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == HIGH && currentState == LOW){
    Serial.println("The button is pressed");
    digitalWrite(ledPin, HIGH);
    analogWrite(pinBuzzer, 10);
  }
  else if(lastState == LOW && currentState == HIGH){
    Serial.println("The button is released");
    digitalWrite(ledPin, LOW);
    
  }
  // save the the last state
  lastState = currentState;
}
 