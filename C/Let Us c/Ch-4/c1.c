#include <stdio.h>
int main()
{
    int a, b;
    printf("Please enter the two numbers:\n");
    scanf("%d%d", &a, &b);
    long long int x = 1;
    int i = 1;
    while (i <= b)
    {
        i++;
        x *= a;
    }
    printf("%d raised to %d = %lld\n", a, b, x);
    return 0;
}