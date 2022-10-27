[<<<---BACK](./)

* * *

![image](https://user-images.githubusercontent.com/109336369/197332477-82a0b36b-187f-4406-a99c-a4cfa704ce24.png)

# 5.1) Write Arduino sketches to subscribe messages from the MQTT broker 

> After we already setup the MQTT Broker on our Raspberry Pi.
> Now we gonna try to connect arduino to MQTT Broker

> ### Required Component 
> * MQTT Broker ( Raspberry Pi )
> * ESP32 + Cable
> * Access Point Device

> ### Required Software
> * Arduino IDE



* * *

### REMARK ! ! ! : 
From my exprience ESP32 device **CANNOT CONNECT TO IOS DEVICE HOTSPOT** ( Iphone 13, In this case )

Might works for others IDK.

![image](https://user-images.githubusercontent.com/109336369/197332768-234ff6cd-19d3-425e-aaee-f7a947b03418.png)

* * *


![image](https://user-images.githubusercontent.com/109336369/197333140-f4c18007-dbb8-46d4-864a-c9007ae219b9.png)

(Didn't know it's already have V2.0)

* * *

#### Step 1 : Setting Up Your Arduino IDE
* You need to setup an arduino IDE before using ESP32 moudle, Hence it not comaptible.
* To Preference then Additional Board Manager.
* Add this link ` https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json `.

![image](https://user-images.githubusercontent.com/109336369/197333226-534f0d6f-e45d-4aad-ac47-c502fe3e3461.png)

* To Board Manager 
* Search for ESP32 Then install

![image](https://user-images.githubusercontent.com/109336369/197333248-56969767-ecaa-443c-9efe-62a52cc2c376.png)

* * *

#### Step 2 : Install Library 
* For other board like ESP8266 needed to use other difference wifi library.
* Install library for MQTT on library manager page.
* In this case we're using library from Adafruit 

![image](https://user-images.githubusercontent.com/109336369/197333467-e0d96488-22c7-49af-a508-f3639794febf.png)

* * *

#### Step 3 : Create arduino_secrets.h for including wifi and mqtt broker information to main code.
* Creating `arduino_secrets.h` in a folder name arduino_secrets.
* Need to be in the folder.
* Example code, Edit your SSID and Password in then if you didn't setup MQTT Broker user and password, just leave it blank.
* 
```
const char WIFI_SSID[] = "YOUR_WIFI_SSID";
const char WIFI_PASS[] = "YOUR_WIFI_PASSWORD";
const char MQTT_USER[] = "MQTT_USERNAME";
const char MQTT_PASS[] = "MQTT_PASSWORD";
```

![image](https://user-images.githubusercontent.com/109336369/197333618-7ac962fe-3952-48e8-bb6a-87ccfe1f92e6.png)

* * *

#### Step 4 : Demo Code for ESP32
* Code are below this.
* After Done Uploading this code to the esp board
* Open up your Serial Monitor to receive from the board
* Set up Baudrate to your match setting (115200, in this case).
* You can see the Received and Publish status between the esp32 board and MQTT Broker.

![image](https://user-images.githubusercontent.com/109336369/197333969-70842ab2-865d-4362-8d00-1177bb9ce56d.png)

* * *

```
#include <WiFiClientSecure.h> // used for TCP/MQTT ports 8883/8884 
#include <PubSubClient.h>     // https://github.com/knolleary/pubsubclient/
#include "arduino_secrets.h"

#define MQTT_BROKER    "test.mosquitto.org"
#define MQTT_PORT      (8883)

#define CLIENT_ID      "arduino_client"
#define SUB_TOPIC      "test/1234/#"
#define PUB_TOPIC      "test/1234/msg"
#define INTERVAL_MSEC  (5000)

WiFiClientSecure net;      // ESP32 WiFi client (Secure)
PubSubClient client(net);  // MQTT client
uint32_t last_pub_ts_msec = 0; 

void connect() {
  // connect the WiFi network first (if not already connected)
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.print( "\n\nWiFi Connected: ");
  Serial.println( WiFi.localIP() ); // show the IP address

  // connect/reconnect the MQTT broker
  while ( !client.connect(CLIENT_ID, MQTT_USER, MQTT_PASS) ) {
    delay(1000);
  }
  client.subscribe( SUB_TOPIC );
}

// This is the callback function for the incoming MQTT message.
void onMessageReceived( char *topic, byte *payload, unsigned int length ) {
  uint32_t now_msec = millis(); // message reception timestamp
  ((char *)payload)[length] = '\0';
  Serial.printf( "Received: topic='%s', payload='%s', rtt=%lu msec\n",
         topic, (char *)payload, now_msec-last_pub_ts_msec );
  Serial.flush();
}

void setup() {
  Serial.begin( 115200 );  // initialize the Serial port
  WiFi.mode( WIFI_STA );   // WiFi Station mode
  WiFi.begin( WIFI_SSID, WIFI_PASS ); // start the WiFi client

#if  defined(MQTT_PORT) && (MQTT_PORT==8883 || MQTT_PORT==8884)
  net.setCACert( MOSQUITTO_CERT_CA );        // set the CA certificate
  #if (MQTT_PORT==8884)
    net.setCertificate( CLIENT_CERT_CRT );   // set client certificate
    net.setPrivateKey( CLIENT_PRIVATE_KEY ); // set private key 
  #endif
#endif

  // initialize the MQTT broker
  client.setServer( MQTT_BROKER, MQTT_PORT ); 
  // set the callback function
  client.setCallback( onMessageReceived ); 
  // set buffer size
  client.setBufferSize( 1024 );
  connect(); // connect the WiFi and the MQTT broker
}

void loop() {
  static uint32_t msg_cnt = 0; // published message count
  static char msg[32]; // message buffer (up to 32 chars)

  if ( !client.connected() ) { 
    connect();   // reconnect the WiFi and/or MQTT if disconnected
  }
  client.loop(); // process the MQTT event (non-blocking call)
  if ( millis() - last_pub_ts_msec >= INTERVAL_MSEC ) {
    sprintf( msg, "hello id=%lu", ++msg_cnt );
    Serial.printf( "Published: '%s'\n", msg );
    Serial.flush();
    // update message publishing timestamp
    last_pub_ts_msec = millis(); 
    // publish a message 
    client.publish( PUB_TOPIC, msg );
  }
}
```

* * *

[<<<---BACK](./)
