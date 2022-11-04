

# Mini-Project Proporsal and Progress Report
2 November, 2022

> Report for : 
> 010123131 Software Development 
> Academic Year 1/2022
> Computer Engineering ( CprE. )
> king mongkut's university of technology north bangkok

* * *
  
# Mini - Project Title : smart gas detector & auto notification

> ### Project Overview :
> 
>	In the 3D printing process of FDM type printers, the melting of plastic processes releases harmful particles into the air. The melting of plastic such as ABS, PETG, or Nylon filaments emits a strong odors and particles, such as VOCs (Volatile Organic Compound) and Dust Particles, that may induce headaches, nausea, or long term effect on health that can cause cancer.
>	This Project has come to save the 3D-printer user. By detecting the gas ( Or other particles emitted from plastic melting in the hotend ) and turn on the ventilator, Air Purifier, or other device of choice. Also user can keep track of the toxic gas in their 3d printing area and control the ventilator device wirelessly via dashboard online

* * *

> ### Disclaimer :
> We are going to use potentiometer as a mock up for MP-503 sensor Due to the experimental process, It's easier to assign value from sensor to trigger the system, because it’s is too much time consuming produce an actual gas to trigger the sensor every time we needed to test our system and it’s not healthy to do that.
> 
> #### Ideal Sensor
> **MP-503 :**
> 
> This sensor is used to measure the air quality.
> It can detect concentration of gasses
> this sensor is highly sensitive to alcohol and smoke
> and also have low power consumption 
>
> **Sharp gp2y1010au0f :**
>
> This sensor used for measure particulate matter (PM)
> It uses an optical sensor to detect the reflected light of dust.
> We can also use this sensor, as we already mentioned, the FDM 3d printer will also emit PM particles such as Plastic Dust or PM2.5. So,  this sensor will be one of our choices to choose what to detect and collect the value.

* * *
 
## Features of This Project :
- Automation
- Healthy
- Keep Statistics
- Status Report
- Discord Dashboard

Expect learning Outcome :
Arduino Programming
Implementing Linux
Virtual Machine
OS Installation
Raspberry Pi ( Raspbian OS )
Using Protocol
MQTT 
Zigbee
Backend
Node-red Integrating Device
Java Script for Data Processing
Command
Influx Database
Dashboard and Display
Data Processing
Discord
Discord Bot
 javascript and python




Components :
Hardware :
Sensor 
MP-503
Potentiometer
(mockup)
Arduino
ESP8266
Zigbee 
Zigbee Reciever
Zigbee smart plug
Laptop 
(for being a host device, Replacing Raspberry Pi )


	Software :
Arduino IDE
Node-Red
MQTT (Protocal)
InfluxDB (Database and dashboard)
Discord (Dashboard display and notification)
Linux OS
Raspberry Imager
Raspbian
Ubuntu
Zigbee2mqtt






Work List & Progess report :














** Remark
done
to do

Research
 Exploring Raspberry Pi OS using a virtual machine (VM) or real hardware (SBC).
 Exploring MQTT broker
 Exploring Zigbee2MQTT
 Exploring Arduino-ESP32

Arduino part 
connect sensor to ESP8266 and publish mqtt message 





Zigbee
 connect zigbee devices with the zigbee2mqtt receiver and manage sensors via the zigbee dashboard.


MQTT Broker
start mqtt broker on host laptop and use it as a protocol to publish and subscribe message
InfluxDB
-  Create Influx database to subscribe data from node-red and keep stat for dashboard

Node-Red 
		     We connect everything in node-red 
- Subscribe data from mqtt broker and receive data from sensor
- Process data in node-red with function using javascript 
- publish message to zigbee2mqtt influxdb and discord

Discord
Coding Discord bot use Python Language that can display data and notification by using command 








