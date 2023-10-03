/*
   *      Author: Stefan Soyka
   *      Date: 05/08/2023
   *      Title: RTC test program
   */

#include "main/main_2.h"
#include "lib/test_lib_1.h"
#include "lib/test_lib_2.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "/usr/local/include/wiringPi.h"

#define led 21


int main() {
    time_t seconds;
    time_t twoseconds;
    int resultAdd;
    int resultSub;
    int resultMul;

    seconds = time(0);
    sleep(2);
    twoseconds = time(0);
    printf("Have a lot of fun with C\n");
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    printf("Seconds since January 1, 1970 = %ld\n", twoseconds);

    printf("LED Test");

    wiringPiSetup();
    pinMode(led, OUTPUT);

    while(1)
    {
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(led, HIGH);
        delay(1000);
    }


    return 0;

}

