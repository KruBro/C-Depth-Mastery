/*
 * Project: Calendar Generator
 * Author: Shahad K
 * 17 Dec 2025
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
