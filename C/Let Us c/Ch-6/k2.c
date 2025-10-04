#include<stdio.h>
#include<math.h>
#include<stdbool.h>

double dist(double x1,double y1,double x2,double y2)
{
    double dis;
    dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return sqrt(dis);
}

double area(double x1,double y1,double x2,double y2, double x3,double y3)
{
    double a,b,c;
    a=dist(x1,y1,x2,y2);
    b=dist(x1,y1,x3,y3);
    c=dist(x3,y3,x2,y2);
    double s=(a+b+c)/2;
    double ar=s*(s-a)*(s-b)*(s-c);
    return sqrt(ar);
}

int in_out(double x1,double y1,double x2,double y2, double x3,double y3, double x,double y)
{
    double A = area(x1,y1,x2,y2,x3,y3);
    double A1 = area(x,y,x1,y1,x2,y2);
    double A2 = area(x,y,x2,y2,x3,y3);
    double A3 = area(x,y,x3,y3,x1,y1);

    double sum = A1 + A2 + A3;

    if(fabs(sum - A) < 1e-6)  // tolerance for floating point
        return 1;  // inside or on boundary
    else
        return 0;  // outside
}
int main()
{
    double x1,y1,x2,y2,x3,y3,x,y;

    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);

    printf("Enter point coordinates (x y): ");
    scanf("%lf %lf",&x,&y);

    if(in_out(x1,y1,x2,y2,x3,y3,x,y))
        printf("Point (%.2lf, %.2lf) is INSIDE or ON the triangle.\n",x,y);
    else
        printf("Point (%.2lf, %.2lf) is OUTSIDE the triangle.\n",x,y);

    return 0;
}