/*
 * Ejemplo leer temperatura y humedad
 * Sensor DHT11 y ESP32s
 */
#include <DHT.h>//https://github.com/adafruit/DHT-sensor-library
#define DHTPIN 2  

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Antes de leer Temp, hum
  //Esperar 2 segundos entre cada lectura
  delay(2000);

  float h = dht.readHumidity();
  // Leer temperatura ÂºC
  float t = dht.readTemperature();
  // si se le pasa a la funcion el parametro true obtenemos la temperatura en ÂºF
  float f = dht.readTemperature(true);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%  Temperatura: ");
  Serial.print(t);
  Serial.print("Â°C  ");
  Serial.print(f);
  Serial.print("Â°F");

}