/*
   *      p3-2.c
   *      Beispielprogramm 2, Abschnitt 3
   */
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t seconds;
    time_t twoseconds;
    seconds = time(0);
    sleep(2);
    twoseconds = time(0);
    printf("Have a lot of fun with C\n");
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    printf("Seconds since January 1, 1970 = %ld\n", twoseconds);
    return 0;

}
