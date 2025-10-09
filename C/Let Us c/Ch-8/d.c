#include<stdio.h>
#define mean(a,b) ((a+b)/2.0)
#define abs(a) (a>0 ? a : -a)
#define upper_to_lower(c) (c+32)

int main()
{
    printf("%.2f\n", mean(10, 15));
    printf("%.2f\n", abs(-169.99));
    printf("%c\n", upper_to_lower('A'));
    return 0;
}