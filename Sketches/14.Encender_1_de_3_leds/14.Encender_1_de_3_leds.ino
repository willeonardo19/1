//Encender uno de 3 leds

const int Led1 = 13;
const int Led2 = 13;
const int Led3 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT); 
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
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    delay(2000);
    
  }
  else if( menu == 2){
    Serial.print("Encendiendo led rojo: ");
    digitalWrite(Led2, HIGH);
    digitalWrite(Led1, LOW);
    digitalWrite(Led3, LOW);

    delay(2000);
  }
  else if( menu == 3){
    Serial.print("Encendiendo led rojo: ");
    digitalWrite(Led3, HIGH);
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);

    delay(2000);
  }
 
}
