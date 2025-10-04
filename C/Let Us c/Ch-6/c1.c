#include <stdio.h>

void roman(int x)
{
    int k;
    k = x / 1000;
    for (int i = 0; i < k; i++)
    {
        printf("m");
    }
    x %= 1000;
    k = x / 500;
    for (int i = 0; i<k; i++)
    {
        printf("d");
    }
    x%=500;
    k=x/100;
    for (int i = 0; i<k; i++)
    {
        printf("c");
    }
    x%=100;
    k=x/50;
    for (int i = 0; i<k; i++)
    {
        printf("l");
    }
    x%=50;
    k=x/10;
    for (int i = 0; i<k; i++)
    {
        printf("x");
    }
    x%=10;
    k=x/5;
    for (int i = 0; i<k; i++)
    {
        printf("v");
    }
    x%=5;
    k=x;
    for (int i = 0; i<k; i++)
    {
        printf("i");
    }
    return;
}

int main()
{
    printf("Please enter a number: ");
    int n;
    scanf("%d", &n);
    roman(n);
    return 0;
}