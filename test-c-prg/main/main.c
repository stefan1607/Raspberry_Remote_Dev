/*
   *      Author: Stefan Soyka
   *      Date: 05/08/2023
   *      Title: RTC test program
   */

#include "main/main_2.h"
#include "lib/test_lib_1.h"
#include "lib/test_lib_2.h"
#include <time.h>
#include <unistd.h>



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

    printf("Some calculations\n");
    printf("Add: %ld", add2integers(2,3));
    printf("\n");
    printf("Sub: %ld", sub2integers(3,2));
    printf("\n");
    printf("Mul: %ld", mul2integers(3,2));
    printf("\n");

    return 0;

}

