#include <stdio.h>

int main()
{
    int n, n1, n2, n5, n10, n50, n100;
    printf("Please enter your N:   ");
    scanf("%d", &n);
    n100 = n / 100;
    n = n - 100 * n100;
    n50 = n / 50;
    n = n - 50 * n50;
    n10 = n / 10;
    n -= 10 * n10;
    n5=n/5;
    n-=5*n5;
    n2 = n / 2;
    n = n - 2 * n2;
    n1 = n;

    printf("The denomination of 100 is :  %d\n", n100);
    printf("The denomination of 50 is :  %d\n", n50);
    printf("The denomination of 10 is :  %d\n", n10);
    printf("The denomination of 5 is :  %d\n", n5);
    printf("The denomination of 2 is :  %d\n", n2);
    printf("The denomination of 1 is :  %d\n",n1);
    return 0;
}