/*
   *      Author: Stefan Soyka
   *      Date: 05/08/2023
   *      Title: RTC test program
   */

#include <time.h>
#include <unistd.h>
// #include <wiringPiI2C.h>
#include "RTClib.h"


RTC_DS3231 rtc;

 char daysOfTheWeek[7][12] = {
    "Sonntag",
    "Montag",
    "Dienstag",
    "Mittwoch",
    "Donnerstag",
    "Freitag",
    "Samstag"
};

void setup () {
    Serial.begin(9600);
    delay(2000);
    rtc.begin(); rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
    /* Um Datum und Uhrzeit manuell einzustellen, Entfernen Sie das Komma
        // Zeichen und geben Sie in der folgenden Zeile neue Werte ein in dieser Reihenfolge:
        // Jahr, Tag, Monat, Stunde, Minute und Sekunde.
    */
    // rtc.adjust(DateTime(2020, 2, 24, 10, 00, 0));
}

void loop () {
    DateTime now = rtc.now();

    // Tag der Woche
    Serial.print("Tag der Woche: ");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.println();


    // eine Registerkarte //Aktuelle Zeit:
    Serial.print("Aktuelle Zeit: ");
    if (now.hour() < 10) {
        Serial.print("0");
        Serial.print(now.hour());
     }
     else {
        Serial.print(now.hour(), DEC);
     }
     Serial.print(':');

    if (now.minute() < 10) {
        Serial.print("0");
        Serial.print(now.minute());
    }
    else {
        Serial.print(now.minute(), DEC);
    }
    Serial.print(':');
    if (now.second() < 10) {
        Serial.print("0");
        Serial.print(now.second());
    }
    else {
        Serial.print(now.second(), DEC);
    }
    Serial.println();


    // eine Registerkarte
    // Aktuelles Datum:
    Serial.print("Aktuelles Datum: ");
    if (now.day() < 10) {
        Serial.print("0");
        Serial.print(now.day());
    }
    else {
        Serial.print(now.day(), DEC);
    }
    
    Serial.print('/');
    if (now.month() < 10) {
        Serial.print("0");
        Serial.print(now.month());
    }
    else {
        Serial.print(now.month(), DEC);
    }
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(""); Serial.println();
    

    //Temperatur:
    Serial.print("Temperatur: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");
    Serial.println();
    delay(2000);

}




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

