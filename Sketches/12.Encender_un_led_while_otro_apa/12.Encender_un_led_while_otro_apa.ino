//encender uno de 3 leds

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
  Serial.println();
  Serial.println("Que led quieres encender? ");
  Serial.println("1. Verde");
  Serial.println("2. rojo");
  Serial.println("3. azul");
  Serial.println();
  
  int menu = Serial.parseInt();

  if (menu == 1){
    Serial.print("Encendiendo led verde: ");
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedRojo, LOW);
    digitalWrite(LedAzul, LOW);
    delay(2000);
    
  }
  else if( menu == 2){
    Serial.print("Encendiendo led rojo: ");
    digitalWrite(LedRojo, HIGH);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedAzul, LOW);
    delay(2000);
  }
  else if( menu == 3){
    Serial.print("Encendiendo led azul: ");
    digitalWrite(LedAzul, HIGH);
    digitalWrite(LedRojo, LOW);
    digitalWrite(LedVerde, LOW);
    delay(2000);
  }
  
}
