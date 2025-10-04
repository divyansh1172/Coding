#include <stdio.h>
#include <math.h>

int main()
{
    float l1, l2, g1, g2, dist_nm;

    printf("Enter lat and long of point 1: ");
    scanf("%f %f ", &l1, &g1);

    printf("Enter lat and long of point 2: ");
    scanf("%f %f ", &l2, &g2);

    dist_nm = 3963 * acos(sin(l1) * sin(l2) + cos(l1) * cos(l2) * cos(g2 - g1));

    printf("The distance between two given points is :  %.2f", dist_nm);

    return 0;
}