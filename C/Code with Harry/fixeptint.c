#include<stdio.h>

double f(double c, double x)
{
    return (x + c/x)/2;
}
int main()
{
    double c, x;
    int n;
    scanf("%lf %d %lf",&c, &n, &x);

    for (int i = 0; i < n; i++)
    {
        x=f(c,x);
    }
    printf("%.10lf", x);
    return 0;
}