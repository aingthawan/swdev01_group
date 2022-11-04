
[<<<---- BACK](./)

* * *

# Mini-Project Proporsal
2 November, 2022

> Report for : 
> 
> 010123131 Software Development 
> 
> Academic Year 1/2022
> 
> Computer Engineering ( CprE. )
> 
> king mongkut's university of technology north bangkok

* * *

![image](https://user-images.githubusercontent.com/109336369/199889985-6cc19047-d32a-4fd4-94b1-db6b326266e8.png)

# Mini - Project Title : smart gas detector & auto notification

> ### Project Overview :
>
> ![image](https://user-images.githubusercontent.com/109336369/199888785-1d5f8741-548b-471a-bd20-dd1109e41703.png)
>
> [Image of Mini-Project Draft Paper]
>
>	In the 3D printing process of FDM type printers, the melting of plastic processes releases harmful particles into the air. The melting of plastic such as ABS, > PETG, or Nylon filaments emits a strong odors and particles, such as VOCs (Volatile Organic Compound) and Dust Particles, that may induce headaches, nausea, or long >term effect on health that can cause cancer.
>	This Project has come to save the 3D-printer user. By detecting the gas ( Or other particles emitted from plastic melting in the hotend ) and turn on the 
> ventilator, Air Purifier, or other device of choice. Also user can keep track of the toxic gas in their 3d printing area and control the ventilator device 
> wirelessly via dashboard online

* * *

> ### Disclaimer :
> We are going to use potentiometer as a mock up for MP-503 sensor Due to the experimental process, It's easier to assign value from sensor to trigger the system,
>  because it’s is too much time consuming produce an actual gas to trigger the sensor every time we needed to test our system and it’s not healthy to do that.
> 
> #### Ideal Sensor
> **MP-503 :**
> 
> ![image](https://user-images.githubusercontent.com/109336369/199888421-17f65038-c042-42e4-9ba1-4f144880dec6.png)
> 
> This sensor is used to measure the air quality.
> It can detect concentration of gasses
> this sensor is highly sensitive to alcohol and smoke
> and also have low power consumption 
>
> **Sharp gp2y1010au0f :**
> 
> ![image](https://user-images.githubusercontent.com/109336369/199888446-4e88b0a6-f908-4073-83c2-183174e54cfe.png)
> 
> This sensor used for measure particulate matter (PM)
> It uses an optical sensor to detect the reflected light of dust.
> We can also use this sensor, as we already mentioned, the FDM 3d printer will also emit PM particles such as Plastic Dust or PM2.5. So,  this sensor will be one of  our choices to choose what to detect and collect the value.

* * *
 
## Features of This Project :
- Automation
- Healthy
- Keep Statistics
- Status Report
- Discord Dashboard

* * *

## Expect learning Outcome :
* Arduino Programming
* Implementing Linux
* Virtual Machine
* OS Installation
	* Raspberry Pi ( Raspbian OS )
* Using Protocol
	* MQTT 
	* Zigbee
* Backend
	* Node-red Integrating Device
		* Java Script for Data Processing
		* Command
	* Influx Database
* Dashboard and Display
	* Data Processing
	* Discord
		* Discord Bot
			* javascript and python

* * *

## Components :
### Hardware :
* Sensor 
	* MP-503
		*Potentiometer (mockup)
* Arduino
	* ESP8266
* Zigbee 
	* Zigbee Reciever
	* Zigbee smart plug
* Laptop (LINUX OS) 
	* (for being a host device, Replacing Raspberry Pi )


### Software :
* Arduino IDE
* Node-Red
* MQTT (Protocal)
* InfluxDB (Database and dashboard)
* Discord (Dashboard display and notification)
* Linux OS
* Raspberry Imager
* Raspbian
* Ubuntu
* Zigbee2mqtt

* * *

[<<<---- BACK](./)
