#include <stdio.h>
#include <math.h>

int main()
{
    int n=11;
    double x[11] = {34.22, 39.87, 41.85, 43.23, 40.06, 53.29, 53.29, 54.14, 49.12, 40.71, 55.12};
    double y[11] = {102.43, 100.93, 97.43, 97.81, 98.32, 98.32, 100.07, 97.08, 91.59, 94.85, 94.65};
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, sum_yy = 0;
    for (int i = 0; i < 11; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
        sum_yy += y[i] * y[i];
    }
    double k=(n*sum_xx - sum_x*sum_x)*(n*sum_yy - sum_y*sum_y);
    k=sqrt(k);
    double r= (n*sum_xy-sum_x*sum_y)/k;
    printf("r=%.4lf\n", r);
    return 0; 
}