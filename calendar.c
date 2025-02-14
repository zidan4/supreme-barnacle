#include <stdio.h>
#include <stdbool.h>

// Determine if a given year is a leap year
bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Get the number of days in a specific month of a year
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
} 

// Calculate the starting weekday (0=Sunday, 1=Monday, …, 6=Saturday)
// for the first day of a given month in a given year.
// Uses a variant of Zeller's Congruence.
int getStartingDay(int year, int month) {
    int m = month;
    int y = year;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    // Zeller's Congruence (h: 0=Saturday, 1=Sunday, ..., 6=Friday)
    int h = (1 + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    // Adjust so that 0 = Sunday, 1 = Monday, …, 6 = Saturday
    int d = (h + 6) % 7;
    return d;
}

// Print the calendar for a specific month and year
void printMonthCalendar(int year, int month) {
    const char *monthNames[] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
    
    printf("      %s %d\n", monthNames[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    int startingDay = getStartingDay(year, month);
    int days = getDaysInMonth(month, year);

    // Print initial spaces for the first week
    for (int i = 0; i < startingDay; i++) {
        printf("   ");
    }

    // Print each day of the month
    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((startingDay + day) % 7 == 0)
            printf("\n");
    }
    printf("\n\n");
}

int main() {
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    // Loop through all months and print the calendar for each
    for (int month = 1; month <= 12; month++) {
        printMonthCalendar(year, month);
    }
    return 0;
}

