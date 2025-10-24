#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2, y = y1 - y2;
    return sqrt(x * x + y * y);
}

int main()
{
    double x[10] = {0}, y[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    double distance = 0;
    for (int i = 1; i < 10; i++)
    {
        distance += dist(x[i - 1], y[i - 1], x[i], y[i]);
    }
    printf("Total distance travelled is %.4lf\n", distance);
    return 0;
}