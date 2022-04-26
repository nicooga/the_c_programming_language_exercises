#include <stdio.h>
#include "lib/input.h"
#include "lib/string.h"

int invoke_day_of_year(void);
int invoke_month_day(void);

int day_of_year(unsigned short year, char month, char day);
void month_day(
    short year,
    short year_day,
    short *pmonth,
    short *pday
);

static char is_leap(unsigned short year);
static int validate_year(short year);
static int validate_month(short month);
static int validate_day(short day);
static int validate_year_day(short year, short year_day);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.
int main(void)
{
    char function_name[100];

    read_word(function_name, 100);

    if (string_equals(function_name, "day_of_year")) return invoke_day_of_year();
    else if (string_equals(function_name, "month_day")) return invoke_month_day();
    else {
        printf("Unknown function \"%s\"\n", function_name);
        return 1;
    }

    return 0;
}

int invoke_day_of_year(void)
{
    short year = read_int();
    short month = read_int();
    short day = read_int();
    if (!validate_year(year)) return 1;
    if (!validate_month(month)) return 1;
    if (!validate_day(day)) return 1;
    printf("%d\n", day_of_year(year, month, day));
    return 0;
}

int invoke_month_day(void)
{
    short year = read_int();
    short year_day = read_int();
    short month;
    short day;
    if (!validate_year(year)) return 1;
    if (!validate_year_day(year, year_day)) return 1;
    month_day(year, year_day, &month, &day);
    printf("%d %d\n", month, day);
    return 0;
}

int validate_year(short year)
{
    if (year > 0) return 1;
    printf("Invalid year `%d`. Year must be a positive number\n", year);
    return 0;
}

int validate_month(short month)
{
    if (month < 1) {
        printf("Invalid month `%d`. Month must be a positive number\n", month);
        return 0;
    }

    if (month > 12) {
        printf("Invalid month `%d`. Month must be a less than or equal to 12\n", month);
        return 0;
    }

    return 1;
}

int validate_day(short day)
{
    if (day < 1) {
        printf("Invalid day `%d`. Day must be a positive number\n", day);
        return 0;
    }

    if (day > 31) {
        printf("Invalid day `%d`. No day can be greater than 31\n", day);
        return 0;
    }

    return 1;
}

int validate_year_day(short year, short year_day)  {
    if (year_day < 1) {
        printf("Invalid year day `%d`. Year day must be a positive number\n", year_day);
        return 0;
    }

    int leap = is_leap(year);
    int days_in_year = leap ? 366 : 365;

    if (year_day > days_in_year) {
        printf(
            "Invalid year day `%d`. Year %d is%s a leap year and has only %d days\n",
            year_day,
            year,
            leap ? "" : " not",
            days_in_year
        );
        return 0;
    }

    return 1;
}

int day_of_year(unsigned short year, char month, char day)
{
    int i;
    int leap = is_leap(year);

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

void month_day(
    short year,
    short year_day,
    short *pmonth,
    short *pday
)
{
    int i;
    int leap = is_leap(year);

    for (i = 1; year_day > daytab[leap][i]; i++)
        year_day -= daytab[leap][i];

    *pmonth = i;
    *pday = year_day;
}

char is_leap(unsigned short year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}