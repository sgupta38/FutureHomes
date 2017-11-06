In this program, simple web server is hosted on the ESP8266 at port 80. This server waits for the client to connect. Client will request either to ON or OFF the LED.

**Steps:**
1. Open the program with Arduino IDE.
2. Verify it so that no error occurs.
3. Connect the device and check for its basic configurations like Communication Port, Baud rate etc.
4. Upload the program.
5. Open the 'Serial Monitor' which is located at upper right corner of IDE.
6. Press the 'Reset' button on the ESP8266. You can see, ESP8266 will connect to Wifi and will print the URL.
7. Copy that URL on the any browser (You can open on  Mobile too)
8. Booooom!!! You can see the two buttons. When 'Green' button is pressed, LED Blinks and when 'Red' button is pressed, LED stops blinking.

**Limitation**
 The only limitation in this approach is that, you will have a limited network area. You can not control your device remotely.
 But I believe, if you want to control your devices in the your home alone, this approach works perfectly.
 
