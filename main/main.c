/*
   *      Author: Stefan Soyka
   *      Date: 05/08/2023
   *      Title: RTC test program
   */

#include "main_2.h"
#include "../lib/test_lib_1.h"
#include "../lib/test_lib_2.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "/usr/local/include/wiringPi.h"
#include "/usr/local/include/lcd.h"


/*  This define is used for control the GPIO on my RaspberryPi 32bit.         */
/*  Numbering of the LEDs you could find out via the command line tool GPIO   */
/*  >gpio readall                                                             */
/*  The column wPI is the one with the correct number                         */

/*  Define data interface for humidity sensor DHT11 data pin */
#define DHT_PIN 21 
#define D4 22
#define D5 23
#define D6 24
#define D7 25
#define RS 2
#define E 3


int WaitEdge(int mode)
{
    int counter = 0;
    while(digitalRead(DHT_PIN) == mode)
    {
        counter++;
        delayMicroseconds(1);
        if(counter == 255) return 1;
    }
    return 0;        
}

//
// This function reads the temperature and humidity from DHT11
// and returns the readings to the calling program
//
void Read_DHT11(int *T, int *H)
{
    char res, i, state, counter,indx = 0;
    int data[5];

    for(i = 0; i < 5; i++)data[i] = 0;
    pinMode(DHT_PIN, OUTPUT);
    digitalWrite(DHT_PIN, LOW);
    delay(18);
    digitalWrite(DHT_PIN, HIGH);
    delayMicroseconds(40);
    pinMode(DHT_PIN, INPUT);

    res = WaitEdge(0);
    res = res +WaitEdge(1);

    i = 0;
    while(i < 80 && res == 0)
    {
        counter = 0;
        if(WaitEdge(0) == 1)break;
        while(digitalRead(DHT_PIN) == HIGH)
        {
            counter++;
            delayMicroseconds(1);
            if(counter == 255)break;
        }

        data[indx/8] <<= 1;
        if(counter > 28)data[indx/8] |= 1;
          indx++;
          i++;
    }

    // Check the Checksum //
    if((indx >= 40) && (data[4] ==
        ((data[0]+data[1]+data[2]+data[3]) & 0xFF)))
    {
        *T = data[2];   // T = data[2].data[3]
        *H = data[0];   // H = data[0].data[1]
    }
}

//
// Start of MAIN program
//
int main(void)
{
    int Temp, Hum, lcd;

    wiringPiSetupGpio();
    delay(1000);
    lcd = lcdInit(2, 16, 4, RS, E, D4, D5, D6, D7, 0, 0, 0, 0);

    while(1) 
    {
        Read_DHT11(&Temp, &Hum);
        lcdClear(lcd);
        lcdPosition(lcd, 0, 0);    // row 0, col 0
        lcdPrintf(lcd, "T = %d C", Temp);
        lcdPosition(lcd, 0, 1);     //row 1, col 0
        lcdPrintf(lcd, "H = %d %%", Hum);
        delay(5000);                // 5s delay
    }

}

