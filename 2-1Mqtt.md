### [🢀 Back to Previous page](./)


# Module 2. Exploring MQTT broker
- This blog is about how i install and run Mosquitto broker on Linux VirtualMachine and Raspberry Pi (RPi) 

Author : Anecha Khumjun 6401012630141

### what is MQTT broker?
- MQTT is a lightweight protocol that supports the Internet of Things (IoT).An MQTT broker is an intermediary entity that enables MQTT clients to communicate. Specifically, an - MQTT broker receives messages published by clients, filters the messages by topic, and distributes them to subscribers.

### 2.1 Install/run Mosquitto broker using Linux VM (Ubuntu or Rapbian OS distro).
- You can choose Linux VM you favorite to install Mosquitto broker this time i will use Raspbian OS . Before installing the MQTT broker to our Raspberry Pi, we need to update  the operating system. All we need to do to update the system is to run the following two commands.
```console
sudo apt update
sudo apt upgrade 
```
- Once the system has finished updating, we can now install the Mosquitto software.Run the following command to install Mosquitto alongside its client software.
```console
sudo apt install mosquitto mosquitto-clients
```
- At this point, you will now have the Mosquitto MQTT broker up and running on your device.You can verify that it is installed and running by using the command below.
```console
sudo systemctl status mosquitto
```
- This command will return the status of the ``` “mosquitto” ``` service.
- You should see the text ``` “active (running)” ``` if the service has started up properly.Like this picture.

![mosquitto-active](/PIC_mqtt_img/mqtt-active.png)

### 2.2 Install Mosquitto broker using RPi hardware.(Do the same thing like install on VM)
- Before installing the MQTT broker to our Raspberry Pi, we need to update the operating system.All we need to do to update the system is to run the following two commands.
```console
sudo apt update
sudo apt upgrade 
```
- Once the system has finished updating, we can now install the Mosquitto software.Run the following command to install Mosquitto alongside its client software.
```console
sudo apt install mosquitto mosquitto-clients
```
- To make Mosquitto auto start when the Raspberry Pi boots, you need to run the following command (this means that the Mosquitto broker will automatically start when the Raspberry Pi starts).
```console
sudo systemctl enable mosquitto.service
```
- At this point, you will now have the Mosquitto MQTT broker up and running on your device.You can verify that it is installed and running by using the command below.
```console
sudo systemctl status mosquitto
```
- This command will return the status of the ``` “mosquitto” ``` service.
You should see the text ``` “active (running)” ``` if the service has started up properly.

![mosquitto-active](/PIC_mqtt_img/mqtt-active.png)

### 2.3 Install/run Mosquitto broker using Docker container (using either Ubuntu VM or RPi)

Not done ...

### 2.4 Use a GUI-based MQTT client to publish messages or subscribe to a topic.
- It have so many GUI-base of MQTT client you can check on this [link to list of GUI-based MQTT client ](https://www.hivemq.com/blog/seven-best-mqtt-client-tools/) but on this contents I will use MQTT Explorer as client on my note book to publish messages or subscribe to a topic. 
First you need to dowload MQTT Explorer [download MQTT Explorer](http://mqtt-explorer.com/).

![web-site-mqtt-ex](/PIC_mqtt_img/mqtt-ex.png)

- Once the system finished installing, we need to run the mosquitto on (RPI) and set it to broker . This is how to set mosquitto broker for (RPI)

### Mosquitto Broker Enable Remote Access (No Authentication)
- Run the following command to open the ```"mosquitto.conf"``` file.
```console
sudo nano /etc/mosquitto/mosquitto.conf
```
- Move to the end of the file using the arrow keys and paste the following two lines.
```console
listener 1883
allow_anonymous true
```
![mosquitto.conf](/PIC_mqtt_img/mqtt-conf.png)

- Then, press CTRL-X to exit and save the file. Press Y and Enter.
- Restart Mosquitto for the changes to take effect.
```console
sudo systemctl restart mosquitto
```

### Testing Mosquitto Broker and MQTT Client
- To subscribe to an MQTT topic with Mosquitto Client open a terminal and enter the command
```console
mosquitto_sub -d -t testTopic
```
![mosquitto_sub](/PIC_mqtt_img/mqtt-sub.png)

- Now your RPI is ready to subscribe massage testTopic Topic.let Publishing message to testTopic Topic by MQTT Client.

### Publishing “Test” Message to testTopic Topic by MQTT Client (USE MQTT-EXPLORER)
- Open your program and change host to your Raspberry Pi IP address.To use Mosquitto broker in your projects, you’ll need to know the Raspberry Pi IP address. To retrieve your - Raspberry Pi IP address, type the next command in your Pi Terminal window.
```console
hostname -I
```
![Raspberry-Pi-IP-address](/PIC_mqtt_img/hostname.png)

![mqtt-ex-change-ip](/PIC_mqtt_img/mqtt-set-ip.png)

- Enter topic name that you want to send massage to for me is "testTopic".and I will send massge "test".

![mqtt-send-msg](/PIC_mqtt_img/mqtt-pub.png)

[mqtt-sub-msg]() no-img



### [🢀 Back to Previous page](./)



