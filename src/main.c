/*
*   Author: Stefan Soyka
*   Date: 15/10/2023
*   Title: I2C test program
*
*   Description:
*   My first Raspberry PI program to get some experience with the I2C communication bus.
*   As a first example I took the temperatur / humidity sensor BMP180 from Bosch.
*   Several documentation was necessary to get all stuff together to realize the small
*   application. This included not only the software and Raspberry, but also also the hardware
*   setup with breadboards, lab power supply as an oscilloscop with I2C decoder.
*   Additional feature is a LCD display to show temperature as humidity
*/


//  C-Standard libraries for Raspberry PI 4
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <unistd.h>


//  Libraries to use the I/O componenten from my Raspberry 4 with bulleye 32bit
//  Due to Gordon not further support the WiringPI library I use a github clone in version 2.70.
//  Further details see: https://github.com/WiringPi/WiringPi and the README.MD in this directory.
    

//  Standard libraries for C
#include "/usr/local/include/wiringPi.h"
#include "/usr/local/include/wiringPiI2C.h"
#include "/usr/local/include/lcd.h"

//  Header file the BMP180 C-File in this directory. It is a modifed copy from the WiringPi orginal
//  source. Therefore it is not used as a library
//#include "bmp180.h"

//  The following libraries are only used to get familiar with the library concept of BAZEL
//#include "../lib/test_lib_1.h"
//#include "../lib/test_lib_2.h"


//  The following defines a used to control the GPIO of the Raspberry PI
//  Numbering of the LEDs you could find out via the command line tool GPIO
//  >gpio readall
//  The column wPI is the one with the correct number.

//  Define the LCD GPIOs to control the display
#define D4 5
#define D5 6
#define D6 17
#define D7 27
#define RS 22
#define E 10


//
// Start of MAIN program
//
int main( void )
{
    printf("BMP180 Test Program ...\n") ;
    /*
    int32_t lcd, fd_bmp180 ;
    int32_t return_code ;

    double fCelsiusTemp, fAirPressure ;            // var to store temperature and airpressure

    // setup the GPIO control WiringPi lib
    return_code = wiringPiSetupGpio() ;
    delay(1000) ;
    fd_bmp180 = bmp180Setup (I2C_ADDRESS) ;
    
    // initialise the LCD
    lcd = lcdInit(2, 16, 4, RS, E, D4, D5, D6, D7, 0, 0, 0, 0) ;

    // welcome message
    printf("BMP180 Test Program ...\n") ;
 
    while(1)
    {
        return_code = bmp180ReadTempPress (fd_bmp180, & fCelsiusTemp, &fAirPressure);   // ACHTUNG: Hier ist fd mit dem Wert 4 angenommen

        lcdClear(lcd);
        lcdPosition(lcd, 0, 0) ;                  // row 0, col 0
        lcdPrintf(lcd, "T = %.2f C", fCelsiusTemp) ;
        lcdPosition(lcd, 0, 1) ;                  //row 1, col 0
        lcdPrintf(lcd, "H = %.2f Pa", fAirPressure) ;
        delay(1000) ;                             // 1s delay
    }

    return return_code ;
*/
    return 0;
}

