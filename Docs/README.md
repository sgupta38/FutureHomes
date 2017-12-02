# FutureHomes
### IoT based home automation.

**Note:** Directory structure is temporary. All these directories will be moved to another location once the actual work starts.

This project is for getting familiar with various home automation protocols and the hardware used for controlling various devices like Light, Camera, AC, Motors etc.

**PROJECT   TYPE:** Custom

**PROJECT   TITLE:** Home automation system using IoT. 

**TOOLS NEEDED:**

1. Arduino IDE
2. ESP8266 NodeMCU
3. Bread Board
4. LEDs and Jumper Cables
5. Relays based on current requirement.
6. Embedded C
7. Python for scripting OTA

**BASIC SCHEDULE:**

1. Team will finalize the requirements
2. Distribution of indivisual task, discussion and integration.
3. Milestone 1:  </br>
    - [x] Get familiar with NodeMCU, mqtt protocol.
    - [x] Hardware requirements discussion & finalization.
    - [x] Finalizing the cloud service for mqtt broker.
    - [ ] Learn OTA in esp8266.
    - [ ] Integration with GSM/GPRS.
4. Milestone 2:</br>
    - [ ] Integration and First Demo with WiFi and GPRS.

**EXPECTED  RESULTS:**

The main crux of the project is to make future homes smarter and energy efficient. The focus is to connect all basic household devices using IoT.
There are myriad number of devices, each having different comminication protocols. Need to identify and find workaround for making all of them work in an uniform way.


## IMP FUNCTIONS.

**void setup()**

The setup() function is called when a sketch starts. Use it to initialize variables, pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board.

**void loop()**

After creating a setup() function, which initializes and sets the initial values, the loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. Use it to actively control the Arduino board.

For more details: https://www.arduino.cc/reference/en/#functions

**PIN structures**

Please refer the PIN_structures image whenver deciding the GPIO pin numbers before hardcoding them in your code. Often people get confused with onboard pin numbers and GPIO pin numbers. This image will always help you in clearing your confusion regarding PIN numbers.
