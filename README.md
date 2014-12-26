#POWER MONITOR

INA219 + PIC24F16KA101 DC voltage, current and power measurement module.

Power Monitor is a small module designed to be placed between the DC power supply and the load. 
It measures the bus voltage, current drawn by the load and calculates the total power consumption.
The results are displayed on a small 0.96" OLED display (SSD1306 controlled via I2C) or
on a SPI controlled PCD5844 (Nokia 5110) LCD.

In addition, the module has an overcurrent alarm feature. A pot is used to set the threshold value (0-1A).
If the measured current exceedes the set threshold, the module will signal it with a pulsing piezo buzzer sound
and a blinking current value on the display.

Since the device was originally designed as an aid while developing guitar effect pedals 
the DC jacks polarity is center negative and the measured current range is set to 0 - 1A.

The device automatically detects if the power jacks are reversed (power applied to the DC out jack)
and kindly asks you to 


###Specs:
- maximum input/bus voltage: 26V DC (INA219B max rating)
- voltage measurement resolution: 10mV 
- measured current range: 0 - 1A (can be changed, refer to the INA219 datasheet)
- current measurement resolution: 50µA
- I alarm range: 0 - 1A, setting the pot to max switches the alarm function OFF
- low dropout reverse supply polarity included
- DC in, DC out jacks: 5.5/2.1mm, center negative
- optional INA219 recalibration mode via UART


###Data outputs:
- SSD1206 OLED display (software I2C)
- PCD8544 LCD (SPI)
- UART (9600 baud)


#Extras:
- hardware I2C pin header
- software I2C pin header (used to driver the OLED display)
- hardware SPI pin header (used to drive the PCD8544 LCD display)
- hardware UART pin header
- ICSP programming pin header
- logic input RB1 


###UART (9600 baud 8b 1Sb NP) commands
NORMAL MODE:

- lcd     data output format, copy of the LCD display
- raw     data output format, raw numbers separated by semicolons 
- stop    stops updating the data via UART
- start   start/resume the data update in 1 second intervals
- rstcnt  resets the measurement counter to 0
- getcnt  returns the actual masurement counter value
- calrst  resets the INA219 calibration constant to theoretic calculated stock value (8192)
- recal   INA219 secodary recalibration mode used to increase the precision. Requires a separate at least 4.5 digit mA/A meter as a reference
- getcal  return the actual INA219 calibration constant value
- y       yep! I confirm
- n       no, thanks.

RECAL MODE:
- xxxx.xx waits for the reference current value (xxxx.xx[mA] format)
- exit    cancel the calibration and return to NORMAL mode



The PCB is designed as a small PIC24F16KA101 dev board and could be used to develop many new projects.
I2C, SPI and UART pins are provided as pin headers for easy interfacing.

License: design is released under

Creative Commons NonCommercial-ShareAlike

CC BY-NC-SA

![CC BY-NC-SA](http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png)

Please contact me for commercial opportunities. 


(c) 07.2014 Piotr Zapart
www.hexeguitar.com
