/***************************************************
  Adafruit MQTT Library ESP8266 Example
 ****************************************************/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "WrongTurn" // your wifi ssid
#define WLAN_PASS       "###" // your wifi password. For open network, just declare it blank as ""

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "notorious"             // your username which was created while registering to Adafruit.
#define AIO_KEY         "###" // Private Key which was created while registering to Adafruit.[Can be found on dashboard.]

#define RELAY_ONE_OUTPUT  3  // GPIO3
#define RELAY_TWO_OUTPUT  1  // GPIO2 *

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'Light' for subscribing to changes.
Adafruit_MQTT_Subscribe Relay_one = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay_one");
Adafruit_MQTT_Subscribe Relay_two = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay_two");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode(RELAY_ONE_OUTPUT, OUTPUT);
  pinMode(RELAY_TWO_OUTPUT, OUTPUT);

  Serial.println(F("Adafruit Relay Control over MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&Relay_one);
  mqtt.subscribe(&Relay_two);

  // For relay, initially it should be off.
  digitalWrite(RELAY_ONE_OUTPUT, HIGH);
  digitalWrite(RELAY_TWO_OUTPUT, HIGH);
}

uint32_t x=0;

void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &Relay_one) {
      Serial.print(F("Got_Relay_one_value: "));
      Serial.println((char *)Relay_one.lastread);
      uint16_t num = atoi((char*)Relay_one.lastread);
      digitalWrite(RELAY_ONE_OUTPUT, num);
    }

    if (subscription == &Relay_two) {
      Serial.print(F("Got_Relay_two_value: "));
      Serial.println((char *)Relay_two.lastread);
      uint16_t num = atoi((char*)Relay_two.lastread);
      digitalWrite(RELAY_TWO_OUTPUT, num);
    }
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}

