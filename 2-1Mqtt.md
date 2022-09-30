# Module 2. Exploring MQTT broker
This blog is about how i install and run Mosquitto broker on Linux VirtualMachine and Raspberry Pi (RPi) 

Author : Anecha Khumjun 6401012630141

### what is MQTT broker?
MQTT is a lightweight protocol that supports the Internet of Things (IoT).An MQTT broker is an intermediary entity that enables MQTT clients to communicate. Specifically, an MQTT broker receives messages published by clients, filters the messages by topic, and distributes them to subscribers.

### 1 Install/run Mosquitto broker using Linux VM (Ubuntu or Rapbian OS distro).
Not do yet.

### 2. Install Mosquitto broker using RPi hardware.
Before installing the MQTT broker to our Raspberry Pi, we need to update the operating system.All we need to do to update the system is to run the following two commands.
```console
sudo apt update
sudo apt upgrade 
```
Once the system has finished updating, we can now install the Mosquitto software.Run the following command to install Mosquitto alongside its client software.
```console
sudo apt install mosquitto mosquitto-clients
```
At this point, you will now have the Mosquitto MQTT broker up and running on your device.You can verify that it is installed and running by using the command below.
```console
sudo systemctl status mosquitto
```
This command will return the status of the ``` “mosquitto” ``` service.
You should see the text ``` “active (running)” ``` if the service has started up properly.


