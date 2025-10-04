#include <stdio.h>

int main()
{
    int days, normal_yrs, leap_yrs, yr, k, i;
    printf("Please enter the current yr:   ");
    scanf("%d", &yr);
    yr = yr - 2001;
    leap_yrs = yr / 4;
    normal_yrs = yr - leap_yrs;
    days = normal_yrs * 365 + leap_yrs * 366;
    k = days % 7;

    switch (k)
    {
    case 0: printf("Monday\n");
        break;
    case 1: printf("Tuesday\n");
        break;
    case 2: printf("Wednesday\n");
        break;
    case 3: printf("Thursday\n");
        break;
    case 4: printf("Friday\n");
        break;
    case 5: printf("Saturday\n");
        break;
    case 6: printf("Sunday\n");
        break;
    }
    return 0;
}
