[<<<---BACK](./)

* * *

# 4.1) Install/run Zigbee2MQTT using Linux VM (Ubuntu or Rapbian OS distro) and RPi hardware.

> ### To install Zigbee2MQTT on Linux or Raspberry Pi, Is done by the same method.
> ![image](https://user-images.githubusercontent.com/109336369/194564576-0719e0eb-cd42-4010-b05c-8b7f43574319.png)

> Required Component
> * Zigbee USB Adapter (In this case, we are using ***Sonoff CC2652P USB Dongle*** )
> ![image](https://user-images.githubusercontent.com/109336369/194566991-bfef5c1f-f1fe-4e13-aee1-7b58b2fc95bb.png)

> ### Step 0 : Install Z-Stack firmware for using Zigbee Dongle with Zigbee2MQTT
> * Install package cc2538-bsl via these command
>   * ``` $ sudo apt install -y python3 python3-pip python3-setuptools ```
>   * ``` $ sudo pip3 install pyserial intelhex python-magic ```
>   * ``` git clone https://github.com/JelmerT/cc2538-bsl ```
>
> * Connect the Zigbee USB to Virtual Machine or Hardware.
> * Check port of connected device, using this command
>   * ``` $ ls -l /dev/serial/by-id ```
> * looking for this kind of text format to determine your connected USB port, For Example :  ``` ../../ttyUSB0 ```
> * Run the command for start up the port for Zigbee USB
>     ``` sudo python3 ./cc2538-bsl/cc2538-bsl.py --bootloader-sonoff-usb ```
> * Install Zigbee Coordinator
>   * Download .zip file from [Z - Stack Firmware Github](https://github.com/Koenkk/Z-Stack-firmware/tree/master/coordinator/Z-Stack_3.x.0/bin/). In this case is CC1352P2_CC2652P_launchpad_coordinator_20220219.zip
>   * The run these command on the downloaded file directory
>     * ``` $ unzip CC1352P2_CC2652P_launchpad_coordinator_20220219.zip ```
>     * ``` $ sudo python3 ./cc2538-bsl/cc2538-bsl.py --bootloader-sonoff-usb \ -e -w -v ./CC1352P2_CC2652P_launchpad_coordinator_20220219.hex ```   

> ### Step 1
> * Install Nodejs 
>   * ```$ sudo apt install -y curl```
>   * ```$ curl -fsSL https://deb.nodesource.com/setup_14.x | sudo -E bash -```
>   * ```$ sudo apt install -y nodejs```
>   * Checking Version of nodejs and nmp 
>     * ``` $ node -v ```
>     * ``` $ npm -v ```
> * Get Zigbee2MQTT Source code from Github and install package.
>   * ``` $ git clone https://github.com/Koenkk/zigbee2mqtt.git ```
>   * ``` $ sudo mv zigbee2mqtt /opt ```
>   * ``` $ sudo chown -R $USER:$USER /opt/zigbee2mqtt ```
>   * ``` $ cd /opt/zigbee2mqtt ```
>   * ``` $ npm ci ```
> * Create and Edit a Configuration file.
>   * ``` nano /opt/zigbee2mqtt/data/configuration.yml ```
>   * Edit COM port to match with yours 
```
homeassistant: false
permit_join: true
mqtt:
  base_topic: zigbee2mqtt
  ## specify the IP address or hostname of your MQTT broker
  server: 'mqtt://localhost:1883'
  #user: xxxx
  #password: xxxx
serial:
  ## specify the serial COM port (e.g. /dev/ttyACM0, /dev/ttyUSB0)
  port: /dev/ttyUSB0
advanced:
  ## specify the ZigBee channel number
  channel: 15
frontend:
  ## enable Web front-end for Zigbee2MQTT on port 8080
  port: 8080
```
> * Add current user to Dialout group to grant access to port
>   * ``` $ sudo usermod -a -G dialout $USER ```
> * START! Zigbee2MQTT
>   * ```npm start```

* * *

> # OH NO! AN ERROR!!!!
> ![image](https://user-images.githubusercontent.com/109336369/194581637-a1e274dc-e2dd-4b6c-8edf-5372730a86a3.png)
>
> * As you can see, the program state that cannot open the specified port
>  * ![image](https://user-images.githubusercontent.com/109336369/194582468-f76030a2-1a14-4f6c-9446-14e37c90927e.png)
> * Its actually caused from the program read the wrong configuration file or You edit the wrong configuration file
> * **TO FIX :** edit COM port in ``` nano /opt/zigbee2mqtt/data/configuration.yaml ``` file ** .yaml NOT .yml **
>  * From my hypothesis, the program choose to read .yaml first if both file was exist in the same directory 
>  * Then I choose to remove ( delete ) the .yml file before retry starting Zigbee2MQTT

* * *

> # GOOD TO GO NOW!
> ## Nice! Its seems like the Zigbee2MQTT is up and running!
> ![image](https://user-images.githubusercontent.com/109336369/194584008-2eb11593-ee39-4a11-a733-07fc04ef1b72.png)
 

* * *

[<<<---BACK](./)
