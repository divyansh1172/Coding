#include <stdio.h>
#include <math.h>

void Check_triangle(float a, float b, float c)
{
    if (a == b && b == c)
    {
        printf("Equilateral triangle\n");
        return;
    }

    else if (a == b || b == c || a == c)
    {
        printf("Isosceles triangle\n");
        return;
    }

    else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a))
    {
        printf("Right angled triangle\n");
        return;
    }
    else
    {
        printf("Scalene triangle\n");
        return;
    }
}

int main()
{
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);

    Check_triangle(a,b,c);
    return 0;
}