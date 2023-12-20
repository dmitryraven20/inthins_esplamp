String ssid_AP = "ESP_WIFI_Lolin";
String ssid_pass = "ESP_8266_123";



char* ssid_client = "";
char* pass_client = ""; 

int web_port = 80;

char* mqtt_broker = "broker.emqx.io";

const int mqtt_port = 1883;

bool wifi_was_conn = false;

const int led = 2;
int led_pin = LED_BUILTIN;