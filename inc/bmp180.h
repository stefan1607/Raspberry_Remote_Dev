/*
 * bmp180.h:
 *	Extend wiringPi with the BMP180 I2C Pressure and Temperature
 *	sensor.
 *	Copyright (c) 2016 Gordon Henderson
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://github.com/WiringPi/WiringPi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with wiringPi.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdint.h>

#define	DEBUG
#define	I2C_ADDRESS	0x77                          // address if I2C device BMP180
#define	BMP180_OSS 0                              // initialization of BMP180


extern int32_t bmp180Setup (const int pinBase) ;
extern int32_t bmp180ReadTempPress (int fd, double * fTemp, double * fPress) ;

