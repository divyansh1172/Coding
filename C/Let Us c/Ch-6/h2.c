#include <stdio.h>
#include <math.h>
int fac(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
double my_sin_x(double x)
{
    double sum = 0;
    for (int i = 1; i < 10; i += 2)
    {
        if (i % 4 == 1)
        {
            sum += pow(x, i) / fac(i);
        }
        else
        {
            sum -= pow(x, i) / fac(i);
        }
    }
    return sum;
}

int main()
{
    double x=1.57;
    printf("The value of sin x is %.5lf\n", my_sin_x(x));
    return 0;
}