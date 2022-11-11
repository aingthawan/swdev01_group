
# Progress Update 

November 4, 2022

![image](https://user-images.githubusercontent.com/109336369/200114907-238c642a-b7bc-48f3-b0a8-a4123cbb0084.png)

* * *

### 0 - Hardware

- Done setting up Esspressif Device 
  - We Done Setting up an ESP device with mockup sensor ( Potentiometer )
    - At first we sending data to the MQTT Broker on Host device
    - Its works perfectly fine, But if the host machine is offline, Data can't be send to the database
  - So, we decided to move to public MQTT Broker 
    - By this method, database can receive data without by passing to the MQTT host machine ( Linux Laptop in this case )
      
- Done setting up Zigbee MQTT device
  - On the host machine, We done setting up Zigbee2MQTT like we done in the practice session. To the smart device we prefer, The smart plug Socket in this case.
 
- Setting up new host device on ubuntu 
  - As we already said, We have host machine for some services on Linux Laptop insted of Rasperry Pi SBC
    - Why we Dont use Raspberry Pi 
      - From our Experience, The Pi itself like to stop working and freeze all the time and its ruin our work progress
      - This can cause from many ways, 
        - Maybe we ssh login from too many devices ( Two Client at most ) 
        - Maybe the power adapter is not sufficient for the board itself
        - Maybe the hardware itself is outdated when compared to the newer version of software
    - So, One of us decided to dedicate his old laptop to be a host machine
      - We decided to use Linux : Ubuntu Desktop Distribution for a new OS on the machine
  - Setup node red
  - Setup Zigbee2MQTT
  - Setup MQTT Broker 
    - Yep we already done it but, lastly 
    - We moved to Public MQTT Broker 

### 1 - Move Database ( InfluxDB ) to 
- Try Moving Database to Cloud Hosting
- Moved to one of our member private server ( Windows Server OS )

### 2 - Update on Node-Red & Discord Bot
- Receiving Sensor Value From MQTT Broker 
- Communicating with Discord Bot
- Communicating with Database

### 3 - Discord bot new features
- Command
- Call graph plotting
- Check Status


* * *
