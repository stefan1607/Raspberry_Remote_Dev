/*
   *      Author: Stefan Soyka
   *      Date: 05/08/2023
   *      Title: RTC test program
   */

#include "main_2.h"
#include "../lib/test_lib_1.h"
#include "../lib/test_lib_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "/usr/local/include/wiringPi.h"
#include "/usr/local/include/wiringPiI2C.h"
#include "/usr/local/include/lcd.h"
#include "/usr/local/include/bmp180.h"


/*  This define is used for control the GPIO on my RaspberryPi 32bit.           */
/*  Numbering of the LEDs you could find out via the command line tool GPIO     */
/*  >gpio readall                                                               */
/*  The column wPI is the one with the correct number                           */

/*  Define device address for BMP180                                            */
#define I2C_ADDRESS 0x77


/*  Define data interface for humidity sensor DHT11 data pin                    */
#define DHT_PIN 9 
#define D4 5
#define D5 6
#define D6 17
#define D7 27
#define RS 22
#define E 10



//
// Start of MAIN program
//
int main(void)
{
    int Temp, Hum, lcd, bmp180, fd; 

    srand(time(NULL));
    wiringPiSetupGpio();
    delay(1000);
    lcd = lcdInit(2, 16, 4, RS, E, D4, D5, D6, D7, 0, 0, 0, 0);

    bmp180 = bmp180Setup (I2C_ADDRESS);


    // Read_DHT11(&Temp, &Hum);
    // Temp = (rand() % 50) -10;
    // Hum = rand() % 100;
        
    lcdClear(lcd);
    lcdPosition(lcd, 0, 0);    // row 0, col 0
    lcdPrintf(lcd, "Hallo Henry, ", 0);
    lcdPosition(lcd, 0, 1);    // row 1, col 0
    lcdPrintf(lcd, "ab ins Bett!", 1);
    delay(5000);                // 5s delay
    
    lcdPosition(lcd, 0, 0);    // row 0, col 0
    lcdPrintf(lcd, "T = %d C", Temp);
    lcdPosition(lcd, 0, 1);     //row 1, col 0
    lcdPrintf(lcd, "H = %d %%", Hum);
    delay(5000);                // 5s delay

    
    printf("BMP180 Test Program ...\n");
    if(wiringPiSetup() < 0) return 1;
    fd = wiringPiI2CSetup(0x77);
  
    load_calibration();
    while(1)
    {
        printf("\nTemperature : %.2f C\n",read_temperature());
        printf("Pressure :    %.2f Pa\n",read_pressure()/100.0);
        printf("Altitude :    %.2f h\n",read_altitude());
        delay(1000);
    }

    return 0;

}

