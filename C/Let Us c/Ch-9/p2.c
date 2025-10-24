#include <stdio.h>

int main()
{
    int n = 10;
    double x[10] = {3.0, 4.5, 5.5, 6.5, 7.5, 8.5, 8.0, 9.0, 9.5, 10.0};
    double y[10] = {1.5, 2.0, 3.5, 5.0, 6.0, 7.5, 9.0, 10.5, 12.0, 14.0};

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / n;

    printf("Linear regression line:\n");
    printf("y = %.4lf + %.4lfx\n", a, b);

    return 0;
}
