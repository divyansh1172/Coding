#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;
    printf("Please enter the coordinates of position:   ");
    scanf("%f %f", &x, &y);

    float mod;
    float k;
    k = x * x + y * y;
    mod = sqrt(k);

    float theta;
    theta = atan(y / x);

    printf("The coordinates (%.2f, %.2f) can be represented as (%.2f, %.2f)", x, y, mod, theta);
    return 0;
}