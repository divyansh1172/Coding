#include <stdio.h>
#include <math.h>

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double ar;
    ar = s * (s - a) * (s - b) * (s - c);
    return sqrt(ar);
}

int main()
{
    double a, b, c;
    a = 12;
    b = 5;
    c = 13;
    printf("The area is %.2lf\n", area(a, b, c));
    return 0;
}