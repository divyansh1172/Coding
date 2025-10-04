#include<stdio.h>

int main()
{
    float x, y;
    printf("Enter a number: ");
    scanf("%f", &x);

    if (x > 0)
    {
        y = x;
    }
    else
    {
        y = -x;
    }

    printf("The absolute value of %f is %f\n", x, y);

    return 0;
}
