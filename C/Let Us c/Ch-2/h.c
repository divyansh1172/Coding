#include <stdio.h>
#include <math.h>

int main()
{
    double deg;
    printf("Please enter the angle in degree: ");
    scanf("%lf", &deg);

    double rad = deg * M_PI / 180.0;

    double val = sin(rad) * sin(rad) + cos(rad) * cos(rad);

    printf("sin^2(theta) + cos^2(theta) = %.10lf\n", val);

    return 0;
}
