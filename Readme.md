


# Power Efficient GPS Tracker


This is an internship project aiming to build a portable GPS Tracker which sends out its GPS coordinates whenever it detects motion either through SMS or to a website application through power efficient means.
## Changelog
- `1.0`  : Initial release with prototype Hardware and GSM communication through SMS.
- ` 1.1` : Added GPRS communication with a hosted website application.
- `1.2` :   Added hardware PCB design with integrated RF section.

## Features

- Robust and RF emission free PCB design.
- Long-lasting battery life with easy  micro-USB Charging.
- USART echo through USB serial interface for easy debugging.
- User-Friendly web-hosted application with Google Maps integration🌍

## Technologie used
- Firmware written on Microchip 8-bit microcontroller AVR128DA48, having good performance and a lot of peripherics for low power usage.
- High frequency RF coplanar wave transmission line with reduced PCB trace width and RF emissions.
- Web Application Front-End built using JavaScript, HTML and CSS and Google Maps API.
- Web App Back-end built with PHP for data access and storing layer.

## Hardware Modules Used

A number of hardware modules were used in order to create this project

-  [SIM808 | SIMCom ](https://simcom.ee/modules/gsm-gprs-gnss/sim808/) - GSM and GPS module used for GPS tracking and mobile communication
- [6DOF IMU 2 Click BMI160 Breakout Board  ](https://www.mikroe.com/6dof-imu-2-click)  or [LIS331DLHTR](https://www.st.com/en/mems-and-sensors/lis331dlh.html)- Power efficient accelerometer used to detect sudden motion.
- [MCHP AVR128DA32 Microcontroller](https://www.microchip.com/en-us/product/AVR128DA32/) - AVR architecture based microcontroller used for main processing and coordination of the GPS tracker.

## Hardware Application 

The GPS tracker will be on from the moment a charged Li-Ion battery is connected. There are various status LED on the PCB board which will notify about the device's functionality. The device's Li-Ion battery can be easily charged through its micro-USB port.
The device has a nano-SIM card slot which can be accessed by the user with a simple SIM-pin. The SIM card must be linked with a functional account tied  to a GSM carrier (Vodafone/Orange/Telekom/Digi etc.) 
![enter image description here](https://i.ibb.co/y50n0cr/Untitled.png)
The device will send out their GPS coordinates whenever it detects any significant motion, and those coordinates can be viewed on the main website application which renders the coordinates on an interactive Google Map.
The user can access the Debugging interface by connecting the micro-USB port at a serial port. If the user connects the serial port to a serial monitor, the device will echo the communication protocol between the GSM module and the microcontroller, thus showing the possible error codes.

## Software Application Notes
The GPS Tracker should be used together with its Web Application.![enter image description here](https://i.ibb.co/PtLpG2C/chrome-PXRp-KR6-M88.png)
This is the main website that come together  with the Hardware Module. Scrolling down will reveal a description of the app. By clicking on the "Visualize on Google Maps", the user will be redirected to the GPS Tracker's GPS coordinates being rendered on a live map, which is updated real-time.
By clicking the Object Tracking switch, we can either follow the tracker as it is uploading new markers, or let the map display new markers without interrupting our movement.

![enter image description here](https://i.ibb.co/zxS64Fg/chrome-g-TD5-Jp-QXg-T.png)
![enter image description here](https://i.ibb.co/HVSjD8G/chrome-i-QXM0a-Tv-XF.png)By clicking on a certain marker, it's information will be displayed for the user:
![enter image description here](https://i.ibb.co/Mfm04rn/chrome-5-ICZ2-XO1-Jy.png)

