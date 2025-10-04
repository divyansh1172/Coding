#include<stdio.h>
#include<math.h>

int main()
{
    double x,y, r;
    scanf("%lf %lf %lf", &x, &y, &r);
    double px, py;
    scanf("%lf %lf", &px, &py);
    double d;
    d=sqrt((x-px)*(x-px) + (y-py)*(y-py));

    if(d==r)
    {
        printf("On the circle\n");
    }
    else if(d>r)
    {
        printf("Outside the circle\n");
    }
    else
    {
        printf("Inside the circle");
    }
    return 0;
}