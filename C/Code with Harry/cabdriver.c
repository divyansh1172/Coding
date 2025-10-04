#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
    double k;
    k = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return k;
}
int main()
{
    double current_x = 0, current_y = 0, n;
    scanf("%lf", &n);
    double  x1, x2, y1, y2;
    double dist;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    dist = distance(x1, y1, current_x, current_y) + distance(x1, y1, x2, y2);
    current_x = x2;
    current_y = y2;
    for (int i = 2; i <= n; i++)
    {
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        if (distance(current_x, current_y, x1, y1) <= 1)
        {
            dist = dist + distance(x1, y1, current_x, current_y) + distance(x1, y1, x2, y2);
            current_x = x2;
            current_y = y2;
        }
    }
    printf("%.2lf", dist);
    return 0;
}