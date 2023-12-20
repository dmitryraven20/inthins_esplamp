#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"
unsigned long previousMillis = 0;
unsigned long interval = 30000;

void setup(void){
  Serial.begin(115200);
  WIFI_init(true);
  server_init();
  MQTT_init();
  pinMode(led, OUTPUT);
  mqtt_cli.publish("esp8266/state", "hello emqx");
}

void loop() {
  server.handleClient ();
  delay(100);
}

void setup(void){
  Serial.begin(115200);
  WIFI_init(true);
  server_init();
  MQTT_init();
  pinMode(led, OUTPUT);
  mqtt_cli.publish("esp8266/state", "hello emqx");
}