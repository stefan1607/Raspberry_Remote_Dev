/*
   *      p3-2.c
   *      Beispielprogramm 2, Abschnitt 3
   */
#include <stdio.h>
#include <time.h>

/*
Dies ist ein Test

*/
int main() {
    time_t seconds;
    seconds = time(0);
    printf("Have a lot of fun with C\n");
    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    return 0;

}
