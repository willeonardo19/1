#include <WiFi.h>
#include "DHT.h"
#include "AzureIotHub.h"
#include "Esp32MQTTClient.h"

#define INTERVAL 3000  //time interval between two consecutive messages in milliseconds

#define DEVICE_ID "ESP32Device"   //device Id you wish to give To identify the device

#define MESSAGE_MAX_LEN 256    //256 bytes is the maximum data

#define DHTPIN 22     

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);  //initializes DHT

// Please input the SSID and password of WiFi
const char* ssid     = "ARRIS-82A2"; // Name of your Wi-Fi Network.
const char* password = "2PP8GH501356"; // Enter your Wi-Fi Network Security Key / Password
//Replace the above placeholders with your WiFi network's credentials.

int messageCount = 1;    //initialize mesage to one
tatic const char* connectionString = "HostName=humedadtemperatura.azure-devices.net;DeviceId=sensortemperaturahumedad;SharedAccessKey=gEsosz0Q7mkgiOCOdh90btGE/LNcbjGPjp0E2e3Wdnw=";
//Replace the above placeholder with the primary connection string of your IoT device.

const char *messageData = "{\"deviceId\":\"%s\", \"messageId\":%d, \"Temperature\":%f, \"Humidity\":%f}"; //message format or the format template

static bool hasWifi = false;

static bool messageSending = true;
static uint64_t send_interval_ms;

// Utilities

static void InitWifi()
{
  Serial.println("Connecting...");

  WiFi.begin(ssid, password);   //wifi begin method is used to connect to cloud
  
  while (WiFi.status() != WL_CONNECTED) {      //returns connected when successfully connected 
    delay(500);
    Serial.print(".");
  }
  
  hasWifi = true;
  
  Serial.println("WiFi connected");
  
  Serial.println("IP address: ");  //we also print Ip Address
  Serial.println(WiFi.localIP());
}

//Function definition

static void SendConfirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result)
{
  if (result == IOTHUB_CLIENT_CONFIRMATION_OK)
  {
    Serial.println("Send Confirmation Callback finished.");
  }
}

// Arduino sketch
void setup()
{
  
  Serial.begin(38400);
  
  Serial.println(F("DHT11 test!"));
  
  dht.begin();
  
  Serial.println("ESP32 Device");
  Serial.println("Initializing...");

  //Initialize the WiFi module
  Serial.println(" > WiFi");
  hasWifi = false;
  
  InitWifi();
  
  if (!hasWifi)
  {
    return;
  }
  
  
  Serial.println(" > IoT Hub");
    
  
  Esp32MQTTClient_Init((const uint8_t*)connectionString);

  //bool Esp32MQTTClient_Init(const uint8_t* deviceConnString, bool hasDeviceTwin = false, bool traceOn = false);
/**
*   Initialize a IoT Hub MQTT client for communication with an existing IoT hub.
*           The connection string is load from the EEPROM.
*    deviceConnString   Device connection string.
*     hasDeviceTwin   Enable / disable device twin, default is disable.
*     traceOn         Enable / disable IoT Hub trace, default is disable.
*
*    Return true if initialize successfully, or false if fails.
*/

  Esp32MQTTClient_SetSendConfirmationCallback(SendConfirmationCallback);

//void Esp32MQTTClient_SetSendConfirmationCallback(SEND_CONFIRMATION_CALLBACK send_confirmation_callback);
/**
*    Sets up send confirmation status callback to be invoked representing the status of sending message to IOT Hub.
*/

  send_interval_ms = millis();
}

void loop()
{
  if (hasWifi)
  {
    if (messageSending && 
        (int)(millis() - send_interval_ms) >= INTERVAL)
    {
      
      char messagePayload[MESSAGE_MAX_LEN];
      
      float temperature = dht.readTemperature();
      
      float humidity = dht.readHumidity();
      
      snprintf(messagePayload,MESSAGE_MAX_LEN,messageData, DEVICE_ID, messageCount++, temperature,humidity);
      //snprintf(char *str, size_t size,  const char *format, ...)
      //snprintf(buffer,    maximum size, const char *format (i.e template), other arguments.....)
      
      Serial.println(messagePayload);
      
      EVENT_INSTANCE* message = Esp32MQTTClient_Event_Generate(messagePayload, MESSAGE);

                                //Esp32MQTTClient_Event_Generate(const char *eventString, EVENT_TYPE type);
/**
*    Generate an event with the event string specified by @p eventString.
*
*   eventString             The string of event.
*
*    EVENT_INSTANCE upon success or an error code upon failure.
*/
      
      Esp32MQTTClient_SendEventInstance(message);

//bool Esp32MQTTClient_SendEventInstance(EVENT_INSTANCE *event);
/**
*     Synchronous call to report the event specified by @p event.
*
*    event the event instance.
*
*    Return true if send successfully, or false if fails.
*/