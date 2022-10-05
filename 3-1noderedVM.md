# 3  Exploring Node-RED
Node-RED is a flow-based development tool for visual programming developed originally by IBM for wiring together hardware devices, APIs and online services as part of the Internet of Things.

## 3.1  Install/run Node-RED using Linux VM (Ubuntu or Rapbian OS distro).
Here is how I install Node-RED using Raspbian OS VM.  

### 1.) Installing and upgrading Node-RED
There is a script to install node.js, npm and Node-RED onto a Raspberry Pi. I found this on [nodered.org](https://nodered.org/docs/getting-started/raspberrypi)  
Running the following command will download and run the script. If you want to review the contents of the script first, you can view it on Github.  
```bash
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```  
After running the script you will get download status like this.  
![DLnodered]()  

### 2.) Run Node-RED
After I finished download, it's time to run it
