#include<stdio.h>
int main()
{
    double x,y;
    scanf("%lf %lf", &x, &y);
    if(x && !y) printf("X axis\n");

    else if(!x && y) printf("Y axis\n");

    else if(!x && !y) printf("origin \n");

    else printf("IN quadrants\n");
    return 0;
}