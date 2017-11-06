
#include <ESP8266WiFi.h> // WiFi Library
 
const char* ssid = "WrongTurn"; // SSID i.e, Name of your WIFI
const char* password = "46364636"; // Your Wifi password, in case you have open network comment the whole statement or just set it to password=""
 
int ledPin = 2; // Onboard LED is connected to GPIO2. Hence, 2
WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // For the board that I am using, digitalWrite HIGH & LOW inverted. nitially LED light will be off 
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
  int value = HIGH;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one VIMP
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<body bgcolor=\"silver\">");
 
  client.print("Led pin is now: ");
 
  if(value == LOW) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<marquee><p><h1> Winter is coming...</h1></p></marquee>");
  client.println("<a href=\"/LED=ON\"\"><button style=\"background:green;height:100px;width:100px\">Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button style=\"background:red;height:100px;width:100px\">Turn Off </button></a><br/>");
  client.println("</body>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}

 
