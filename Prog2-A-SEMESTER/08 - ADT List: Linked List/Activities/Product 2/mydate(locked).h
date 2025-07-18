#ifndef MYDATE_H
#define MYDATE_H

typedef struct {
    int date, month, year;
} Date;

// Function to check if a year is a leap year
int isLeapYear(int year);

// Function to get the number of days in a month
int daysInMonth(int month, int year);

// Function to calculate the total number of days from a given date
int totalDays(Date d);

// Function to calculate the difference in days between two dates
int differenceDate(Date d1, Date d2);

#endif
