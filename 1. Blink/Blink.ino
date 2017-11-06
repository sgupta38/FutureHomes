/*
 
 Blink the blue LED on the ESP-12E module
 This example code is in the public domain
 
 The blue LED on the ESP8266 module is connected to GPIO2
*/
#define LED_BUILTIN 2               // For esp8266, builtin LED is connected at GPIO2.[This value differs from boards to board.]
                                     // After so much of trial and error I came to know that LED is associated with GPIO2 ;)
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED off by making the voltage HIGH. 
                                     
  delay(1000);                      // Wait for a 1 second
  digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off by making the voltage HIGH.
  delay(2000);                      // Wait for two seconds
}
