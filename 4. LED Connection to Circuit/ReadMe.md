**Real time LED on/off using MQTT dashboard.**
 
In this program, your ESP8266 device will subscribe itself to Adafruit's MQTT broker. From Adafruit's dashboard you can create the topic and publish your messages.
Once message is published, it will be conveyed to all the subscriber's located at any location [ Ofcourse Internet Connection is prerequisite].
Based on this received message, device/devices will take appropriate action/actions.

**Note:** Make sure you have installed the Adafruit's MQTT library and have created the account with Adafruit. Cautiously notedown the **'Private Key'** and **'Username'**.
Also, the names of 'feeds' are **case sensetive.**

**Steps:**
1. Connect the Jumper cables to your cicuit. Connect one end of the wire to 'GND' (ground of your circuit) and another end to the 'LED'. Similarly, noe connect the one end of another jumper wire to pin 'D5' (GPIO 14) on your circuit and another end to 'LED'. </br>

2. For me initially, it was very difficult to determine which end of the LED shall connect to GND? Because LED has two Legs out of which one is longer and another is shorter. As I was from pure CS background, I took help from friend having experience in electronics background and he explained me in simple thing that, **Connect Longer Leg to GPIO pin** and **Connect Shorter Leg to GND pin**. Thats, it I am using this formula from their onwards. </br>

3. Now, just burn your program and goto MQTT dashboard and start turning LED on/off. </br>





 
