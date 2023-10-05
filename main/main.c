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


/*  This define is used for control the GPIO on my RaspberryPi 32bit.         */
/*  Numbering of the LEDs you could find out via the command line tool GPIO   */
/*  >gpio readall                                                             */
/*  The column wPI is the one with the correct number                         */
#define led 21

#define led_r 0
#define led_g 2
#define led_b 3



int main(void) {

    time_t seconds;
    time_t twoseconds;

    int Red, Green, Blue;


/*  Some simple experiments with own libraries and the standard time library  */
    seconds = time(0);
    sleep(2);
    twoseconds = time(0);

    printf("First I made some simple stuff with the standard time library to get experience\n");
    printf("with self build library functions and bazel to build the executable.\n");
    printf("Have a lot of fun with C\n");
    printf("\n");
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    printf("Seconds since January 1, 1970 = %ld\n", twoseconds);
    printf("\n");
    printf("Some calculations\n");
    printf("Add: %d", add2integers(2,3));
    printf("\n");
    printf("Sub: %d", sub2integers(3,2));
    printf("\n");
    printf("Mul: %d", mul2integers(3,2));
    printf("\n");
    printf("\n");
    

/*  Now it gets more interesting stuff. Control the GPIOs on a RaspberryPi    */
/*  with 32bit operating system. I use the WiringPi lib which is not further  */
/*  supported by Gordon Henderson www.wiringpi.com, but a group of people is  */
/*  taking care on GitHub to maintain the library for RaspberryPI.            */ 
/*  I use the 2.70, is a clone of a GitHub respository and compiled and       */
/*  linked on my RaspberryPi.                                                 */
/*  See README.md for further information                                     */

/*  We start with switch on and off a LED. */
    printf("LED Test on a RaspberryPi with a 32bit operating system\n");

    wiringPiSetup();
    pinMode(led, OUTPUT);
    pinMode(led_r, OUTPUT);
    pinMode(led_g, OUTPUT);
    pinMode(led_b, OUTPUT);
    

    printf("Reset the digital GPIO21 to LOW\n");
    digitalWrite(led, LOW);

    for( int i = 0; i<100; i++)
    {
        digitalWrite(led, HIGH);
        delay(100);
        digitalWrite(led, LOW);
        delay(100);
    }

    digitalWrite(led, LOW);
    printf("End of the LED Test\n");
    printf("\n");

    printf("Start RGB LED test\n");

    while(1) {
        Red = rand() %2;                // Between 0,1
        Green = rand() %2;              // Between 0,1
        Blue = rand() %2;               // Between 0,1

        digitalWrite(led_r, Red);
        digitalWrite(led_g, Green);
        digitalWrite(led_b, Blue);
        delay(200);
    }
     
    printf("Start RGB LED test\n");

    return 0;

}

