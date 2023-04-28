//ingreso de serial monitor en codigo 

void setup() {
 Serial.begin(9600);   

 Serial.print("Presiona una tecla: "); 
}

void loop() {
  if (Serial.available()) {
    Serial.print(Serial.read());
  }
}