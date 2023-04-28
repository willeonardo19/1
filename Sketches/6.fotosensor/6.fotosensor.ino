// Detector de luz con LDR
//http://www.practicasconarduino.com/manualrapido/detector_de_luz.html

const int pinLED = 13;
void setup() {

  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int v = analogRead(A0);
  // El valor 600 (siguiente línea) se debe de ajustar dependiendo de la luz en el local
  // y del valor de la resistencia pull-down
  // poca luz -> v pequeño, mucha luz -> v grande. 
  if (v < 600) digitalWrite(pinLED, HIGH); 
  else digitalWrite(pinLED, LOW);
  Serial.println(v);
}

