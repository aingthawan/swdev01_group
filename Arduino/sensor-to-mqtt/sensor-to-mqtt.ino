#include <SPI.h>
#include <WiFi.h>
#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "Atom";
const char* password =  "12345678";
#define mqttServer IPAddress(192, 168, 217, 75)
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";
const int analogInPin = A0;

int Value = 0;
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client")) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }

}
 
void loop() {
  Value = analogRead(analogInPin);

  if (Value > 500) {
     Serial.println(Value); Serial.print("Turn on fan !!");
     client.publish("esp/voc-sensor","Turn on fan"); //Send msg to mqtt-broker
  }
  else {
    Serial.println(Value);
    
  }
  client.loop();
  delay(1000);
}
