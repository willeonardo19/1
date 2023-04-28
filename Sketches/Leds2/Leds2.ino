const int Led1 = 13;
const int Led2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT); 
}

void loop() {
  Serial.println();
  Serial.println("Que led quieres encender? ");
  Serial.println("0. Verde");
  Serial.println("1. rojo");
  Serial.println();
  
  int menu = Serial.parseInt();

  if (menu == 0){
    Serial.print("Encendiendo led verde: ");
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    delay(2000);
    
  }
  else if( menu == 1){
    Serial.print("Encendiendo led rojo: ");
    digitalWrite(Led2, HIGH);
    digitalWrite(Led1, LOW);
    delay(2000);
  }
 
}
