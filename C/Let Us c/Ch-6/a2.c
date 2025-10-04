#include <stdio.h>
#include <math.h>

void nexx(int a[5], int *sum, float *avg, double *dev)
{
    *sum = 0;
    for (int i = 0; i < 5; i++)
    {
        *sum += a[i];
    }
    *avg = *sum / 5;
    double k = 0;
    for (int i = 0; i < 5; i++)
    {
        a[i] -= *avg;
        k += a[i] * a[i];
    }
    k /= 5;
    *dev = sqrt(k);
}

int main()
{
    int a[5], sum;
    a[0] = 5;
    a[1] = 10;
    a[2] = 15;
    a[3] = 20;
    a[4] = 25;
    float avg;
    double dev;
    nexx(a, &sum, &avg, &dev);
    printf("The sum of the given numbers is %d\n", sum);
    printf("The average of the given numbers is %.2f\n", avg);
    printf("The sd of the given numbers is %.2lf\n", dev);
    return 0;
}