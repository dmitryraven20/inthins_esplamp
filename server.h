#include <ESP8266WebServer.h>

ESP8266WebServer server(web_port);

void handle_root() {
  String page_code = "<form action=\"/LED\" method=\"POST\">";
  page_code += "<input type=\"submit\" value=\"Switch LED\">";
  page_code += "</form>";

  server.send(200, "text/html", page_code);

}

void handle_led() {
  bool current = digitalRead(led_pin);
  digitalWrite(led_pin, !current);
  server.sendHeader("Location", "/");
  server.send(303);

}

void handle_reg() {
  String message = "Number of args received:";
  message += server.args();
  message += "\n";


  ssidCLI = const_cast<char*>(server.arg(0).c_str());
  passwordCLI = const_cast<char*>(server.arg(1).c_str());
  
  WiFi.softAPdisconnect(true);
  WIFI_init(false);

  server.send(200, "text/plain", message);
}

void handle_sensor() {                          
  int data = analogRead(A0);
  //server.sendHeader("Location","/");
  server.send(200, "text/html", String(data));
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); 
}


void server_init() {
  server.on("/", HTTP_GET, handle_root);
  server.on("/LED", HTTP_POST, handle_led);
  server.on("/SENSOR", HTTP_GET, handle_sensor);  
  server.onNotFound(handleNotFound);        

  server.begin();
  Serial.println("HTTP server is on" + String(web_port));


}






