For the ESP8266 NodeMCU board that I possess, digitalWrite HIGH & LOW inverted i.e, LED starts blinking at LOW state and stops blinking at HIGH state.
For you, if its not working, try swapping the values of LOW and HIGH in production code.

Some of those boards have the LED connected to VCC, probably because the MCU can sink more (the needed) current in the I/O pins at lower level.
This way, the LED only lights in the LOW state of the pin when it outputs about 0V

Steps:
1. Open the program with Arduino IDE.
2. Verify it so that no error occurs.
3. Connect the device and check for its basic configurations like Communication Port, Baud rate etc.
4. Upload the program.
5. When Done, LED will start blinking. 