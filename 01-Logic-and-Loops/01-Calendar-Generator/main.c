/*
Project 01: The Forever Calendar
Goal: Create a program that generates a perfectly formatted calendar for any year entered by the user (from 1900 onwards).
1. Core Concepts
Modulo Arithmetic (%): Used to wrap days of the week (0-6) and calculate leap years.
Complex Conditionals: Implementing the specific "4-100-400" rule for leap years.
Loops & Accumulators: Calculating the "offset" of days relative to a fixed point in history.
Formatting (printf): Managing whitespace to align the grid of dates perfectly.

2. The Logic Design

A. The Leap Year Algorithm
A year is a leap year if:
It is divisible by 400. (e.g., 2000 ✅)
ELSE if it is divisible by 100, it is NOT a leap year. (e.g., 1900 ❌)
ELSE if it is divisible by 4, it IS a leap year. (e.g., 2024 ✅)
Otherwise, it is a normal year.

B. The "Anchor Day" Algorithm
Since computers don't know days, we calculate them relative to a known fixed date.
Anchor: January 1st, 1900 was a Monday (Index 0).
The Shift:
Normal Year (365 days): 365 % 7 = 1. (Day shifts forward by 1).
Leap Year (366 days): 366 % 7 = 2. (Day shifts forward by 2).
Algorithm:
Initialize total_days_offset = 0.
Loop from y = 1900 up to target_year - 1.
If y is a leap year, add 2 to total_days_offset.
Else, add 1 to total_days_offset.
StartDay = total_days_offset % 7.

3. Sample Output:
Enter a year: 2024

  ------------ January ------------
  Mon  Tue  Wed  Thu  Fri  Sat  Sun
    1    2    3    4    5    6    7
    8    9   10   11   12   13   14
   15   16   17   18   19   20   21
   22   23   24   25   26   27   28
   29   30   31

  ------------ February ------------
  Mon  Tue  Wed  Thu  Fri  Sat  Sun
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29

4. Implementation Plan
isLeapYear(int year): Returns 1 (true) or 0 (false).
getFirstDayOfYear(int year): Loops from 1900 to calculate the start index (0-6).
printCalendar(int year, int startDay):
Array daysInMonth[] = {31, 28, ...}.
Update Feb to 29 if leap year.
Loop 0-11 for months.
Inner loop to print leading spaces .
Inner loop to print days. Break line \n every 7 days.
*/ 

#include <stdio.h>

//Function Prototypes
int isLeapYear(int);
int getFirstDayofYear(int);
void printCalendar(int, int);

int main()
{
    int year, startDay;
    printf("Enter the year: ");
    if(scanf("%d", &year) != 1 && year >= 1900)
    {
        printf("Enter the year in number, the year should be greater than or equal to 1900!\n");
        return 1;
    }

    // Step 1: Calculate the starting day (0=Mon, ... 6=Sun)
    startDay = getFirstDayofYear(year);
    //Print the Calendar
    printCalendar(year, startDay);
}

//400 -> Yes, 100 -> No, 4 -> Yes
int isLeapYear(int year)
{
    if(year % 400 == 0)  return 1;
    if(year % 100 == 0) return 0;
    if(year % 4 == 0) return 1;
    return 0;
}

//Loop from 1900, shift by 2 for leap, 1 for normal
int getFirstDayofYear(int year)
{
    int day = 0; //Jan 01, 1999 was Monday(0)

    for(int i = 1900; i < year; i++)
    {
        if(isLeapYear(i))
            day = (day + 2) % 7; //Leap year shifts two day
        else
            day = (day + 1) % 7; //Normal year Shifts one day
    }

    return day;
}

void printCalendar(int year, int startDay)
{
    char *months[] = {"January", "February", "March", "April", "May", "June", 
                    "July", "August", "September", "October", "November", "December"};
    
    //Standard Days in Months
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentDayOfWeek = startDay;
    //Adjust For Leap Year
    if(isLeapYear(year))
        daysInMonth[1] = 29;
    
    printf("\n ***CALENDAR for %d ***\n", year);

    for(int i = 0; i < 12; i++)
    {
        printf("\n ---------- %s ----------\n", months[i]);
        printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

        //To Print leadings spaces in the start if day is not starting on Monday, Tuesday ... etc
        for(int space = 0; space < currentDayOfWeek; space++)
        {
            printf("     ");
        }

        //To Print Dates
        for(int d = 1; d <= daysInMonth[i]; d++)
        {
            printf("%5d", d);
            // If we hit Sunday (index 6), reset to Monday (0) and new lin
            if(++currentDayOfWeek > 6)
            {
                currentDayOfWeek = 0;
                printf("\n");
            }
        }
        // Final newline if the month didn't end on Sunday
        if(currentDayOfWeek != 0)
            printf("\n");
    }
    printf("\n");
}