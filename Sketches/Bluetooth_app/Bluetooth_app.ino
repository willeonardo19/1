#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11); 
char caracter;
int Pin13 = 13;

void setup() { 
BT.begin(9600); 
Serial.begin(9600);
pinMode(Pin13, OUTPUT); 
}

void loop() { 
if(BT.available()) {
  caracter = BT.read();
  Serial.print(caracter);
  if(caracter == '0')
    { 
      digitalWrite(Pin13, LOW);
    }
    if(caracter == '1')
    { 
      digitalWrite(Pin13, HIGH);
    } 

  } // =>Fin del available

} // =>Fin del loop