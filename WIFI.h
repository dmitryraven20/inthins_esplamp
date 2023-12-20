#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifi_multi;
WiFiClient wifi_client;

String ip = "(IP unset)"; // "192.168.4.1"

String id() {
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  int last = WL_MAC_ADDR_LENGTH - 1;
  int prelast = WL_MAC_ADDR_LENGTH - 2;
  WiFi.softAPmacAddress(mac);
  String id = String(mac[prelast], HEX) +
              String(mac[last], HEX);
  return id;
}

bool start_AP_mode() {
  IPAddress AP_IP(192, 168, 4, 1);
  IPAddress mask(255, 255, 255, 0);
  String ssid_name = ssid_AP + id();
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(AP_IP, AP_IP, mask);
  WiFi.softAP((ssid_AP + " " + id()).c_str(), ssid_pass.c_str());

  ip = WiFi.softAPIP().toString();
  Serial.println("WiFi up in AP mode, " + ssid_name);
  return true;
}

void StartCLIMode() {
  wifiMulti.addAP(ssidCLI, passwordCLI);
  //it is possible to add more networks to connect
  while(wifiMulti.run() != WL_CONNECTED) {
       
  }
}

void WIFI_init(bool mode_ap) {
    if (mode_ap) {
      StartAPMode();
      ip = WiFi.softAPIP().toString();
    } else {
      StartCLIMode();
      ip = WiFi.localIP().toString();
    }
    Serial.println("IP address: ");
    Serial.println(ip);  
}