void setup() {
 Serial.begin(9600);   

 Serial.print("Presiona una tecla: "); 
}

void loop() {
  if (Serial.available()) {
    Serial.write(Serial.read());
  }
}