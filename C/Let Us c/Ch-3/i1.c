#include<stdio.h>

int main()
{
    float len, bre, area, peri;
    printf("Please enter the length and breadth of the rectangle: ");
    scanf("%f%f",&len, &bre);

    area=len*bre;
    peri=len+bre;

    if(area>peri)
    {
        printf("area of reactangle is greater than perimeter\n");
    }

    else if (area<peri)
    {
        /* code */
        printf("area of reactangle is less than perimeter\n");
    }
    else
    printf("area and perimeter are equal\n");

    return 0;
}