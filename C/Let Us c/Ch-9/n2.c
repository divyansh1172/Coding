#include <stdio.h>
#include <math.h>

double area_of_triangle(double a, double b, double theta)
{
    return 0.5 * a * b * sin(theta);
}

int main()
{
    double a[6] = {137.4, 155.2, 149.3, 160.0, 155.6, 149.7};
    double b[6] = {80.9, 92.62, 97.93, 100.25, 68.95, 120.0};
    double theta[6] = {0.78, 0.89, 1.35, 9.00, 1.25, 1.75};
    double area[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        area[i] = area_of_triangle(a[i], b[i], theta[i]);
    }
    int i_max = 0;
    double area_max = area[0];
    for (int i = 1; i < 6; i++)
    {
        if (area[i] > area_max)
        {
            i_max = i;
            area_max = area[i];
        }
    }
    printf("The max area is in %dth entry with area %.4lf\n", i_max, area_max);
    return 0;
}