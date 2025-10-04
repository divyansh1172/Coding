#include<stdio.h>
int main()
{
    double pop=100000;
    for (int i = 10; i >=1; i--)
    {
        printf("at the end of %d years, the population is %lf \n", i, pop);
        pop/=1.1;
    }
    return 0;
}