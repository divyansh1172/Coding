#include <stdio.h>
#include <math.h>

double std_dev(double *a, int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    double mean = sum / n;

    double variance = 0.0;
    for (int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance /= n; // use (n - 1) for sample std deviation

    return sqrt(variance);
}

int main()
{
    double x[15] = {-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2};
    int n = sizeof(x) / sizeof(x[0]);

    printf("Standard deviation: %.4lf\n", std_dev(x, n));

    return 0;
}
