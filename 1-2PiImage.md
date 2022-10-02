[<<<---- BACK](./)
* * * 
# 1.2) Install Raspberry OS on Micro SD Card

> **Overall Requirement**
>  - Install Raspberry OS on MicroSD
>  - Using MicroSD For booting OS on Raspberry PI

> **Tools and Hardware**
> - MicroSD Card ( At least 8 Gb )
> - MicroSD Card Reader
> - Raspberry Pi + ( Power Adapter )
> - Your PC of Choice
> ![image](https://user-images.githubusercontent.com/109336369/193408372-2367dddf-f3c1-4522-9e9b-2e457fdd553a.png)
> 

* * *
# Part 1 : Create Bootable MicroSD

> **Step 1 :  Download  Material**
> - Download **Raspberry OS image** and **Raspberry Pi Imager** form [Raspberry PI Official Website](https://www.raspberrypi.com/software/)
> ![image](https://user-images.githubusercontent.com/109336369/193320710-d3ed6060-595c-4110-b25e-7083aa037526.png)
> 
> - For  Raspberry OS image, Enter " Manually install an operating system image " and Download OS image from the Raspberry Pi OS (64-bit) : Raspberry Pi OS with desktop.
> ![image](https://user-images.githubusercontent.com/109336369/193320759-e41ebb66-a44a-4d8b-9a13-f161ea6e91d2.png)
> ![image](https://user-images.githubusercontent.com/109336369/193320813-a755b62f-bbd8-41d2-ad33-e84bf7f17d2a.png)


> **Step 2 : Install Raspberry Pi Imager**
> - from downloaded file Run the Install Raspberry Pi Imager Setup.
>![image](https://user-images.githubusercontent.com/109336369/193320897-9665678b-9186-4789-a0f9-ad11ec342c4c.png)


> **Step 3 : Setting Up Before Imager before write**
> - **Now, Connect your MicroSD Storage** to your PC via Card Reader
> - Choosing Storage, Choose your Connected storage
> -  Choosing OS, Select **Use Custom,** Then Select your downloaded OS image (.img.xz) file
>  ![image](https://user-images.githubusercontent.com/109336369/193320987-c368a76e-c245-41f0-8cde-03951d9bd8e3.png)
>  ![image](https://user-images.githubusercontent.com/109336369/193321024-23e05518-6596-4622-952a-4aa66713d225.png)
>  ![image](https://user-images.githubusercontent.com/109336369/193321063-05e0bd28-1bb5-466e-b72c-8bab3c621e01.png)
>  ![image](https://user-images.githubusercontent.com/109336369/193321085-c0770cec-986c-4f00-b65c-1c25c8fa05df.png)
>  **Step 3.1 : Advanced Options Setting**
>  - This part is for setting up Pi for 
>  -- Connect to Wireless Network
>  -- Enable SSH Service, Setup your username and password
>  -- Set Hostname
>  ![image](https://user-images.githubusercontent.com/109336369/193321344-734c3e86-0e55-4141-9429-4ee463219d02.png)
>   > ***A Words From Experienced User***
>   >  - Don't use IOS device as hotspot for wireless network, Its not stable ( For Our Case ) or even not connect.
>  

> **Step 4 : Write**
> - Clike "WRITE"
> - Then wait... and done
>  

* * * 
# Part 2 : Boot OS on PI

> First of all, After this it should be just pluging a MicroSD to the Raspberry Pi, Power on the SSH in via cmd or something else.
> **But !** In our case the Board itself not or cannot connect to the network
>  So! Our solution is 


> - Need more equipments 
>   - Capture Card
>   - Mouse
>   - Keyboard
> - Connect 
>   - Mouse + Keyboard ---->> Raspberry Pi USB port
>   - Raspberry Pi HDMI port ---->> Capture Card ---->> PC USB ( By the way you can just connect the HDMI to some monitor anyway ( - _ -  )'  )
> - Open Camera on your PC 
>   - Click on swap camera function until you find your Raspberry Pi monitor.
> - Now
>   - Setup your wireless connection again, Then you are ready for SSH.
> - SSH
>   - On your PC Terminal type the command
>        `ssh user@ip` 
>
>![image](https://user-images.githubusercontent.com/109336369/193408989-17c07fcc-7d89-4f4e-858c-6defc62fa784.png)

* * *

[<<<---- BACK](./)




