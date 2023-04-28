/*
Encender 3 leds x 2 segundos y luego apagarlos x 1 segundo

*/

const int LedVerde = 13;
const int LedRojo = 10;
const int LedAzul = 8;

void setup() {
  Serial.begin(9600);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRojo, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  
}

void loop() {
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedRojo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(2000);  
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAzul, LOW); 
   delay(1000);  

}
