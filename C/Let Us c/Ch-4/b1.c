#include <stdio.h>

int main()
{
    int n;
    printf("Please enter a num:\t");
    scanf("%d", &n);
    long long int fac = 1;
    int i = 1;
    while (i <= n)
    {
        fac *= i;
        i++;
    }
    printf("The factorial of %d is %lld", n, fac);
    return 0;
}