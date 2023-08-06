# Using RTC Modul via I2C
Author: Stefan Soyka

Date: 06/08/2023


## Introduction
This program example should demonstrate the usage of a RTC IC for Raspberry PI. In this case we use the AZdelivery module DS3231 (see Stefans datasheet lib. More detailed description about this project you will find in the book "C-Programming on raspberry pi",ISBN: 978-3-89576-431-8, chapter 7 "I2C Bus Interface.

## Configuration of the raspberry pi
Acitivate I2C interface

> pi@raspberrypi: $ sudo raspi-config
- Move down to **Interface Option** and press **Enter**
- Select **I2C** and press **Enter** to enable it

##  check I2C interface
> pi@raspberrypi: $ sudo i2cdetect -y 1



