#include <stdio.h>
#include <math.h>

int main()
{
    double num, k, log_val;
    scanf("%lf %lf", &num, &k);
    log_val = num;
    int i = 0;
    for (i = 2; i <= k; i++)
    {
        log_val = log_val + (pow(-1, i + 1) * pow(num, i)) / i;
    }
    printf("%.4lf\n", log_val);
    return 0;
}