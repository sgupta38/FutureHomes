Limitation With the Browser approach. [Refer example 2]
	The only limitation in this approach is that, you will have a limited network area. You can not control your device remotely.
	Imagine you are at USA and wants to control your devices located at India..!! Yes, that is possible with the help of MQTT ptotocol.[http://mqtt.org/]
 
In this program, your ESP8266 device will subscribe itself to Adafruit's MQTT broker. From Adafruit's dashboard you can create the topic and publish your messages.
Once message is published, it will be conveyed to all the subscriber's located at any location [ Ofcourse Internet Connection is prerequisite].
Based on this received message, device/devices will take appropriate action/actions.


Steps:
There are many steps and each step really matters a lot.
Please go through the following video tutorial. [https://www.youtube.com/watch?v=ekav8Le5a7U#action=share]

Make sure you have installed the Adafruit's MQTT library and have created the account with Adafruit. Cautiously notedown the 'Private Key' and 'Username'.
Also, the names of 'feeds' are case sensetive.


 