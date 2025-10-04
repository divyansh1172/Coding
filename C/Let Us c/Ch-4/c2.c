#include<stdio.h>
int main()
{
    int fac=1;
    float sum=0;
    for(int i=1; i<=50; i++)
    {
        fac*=i;
        sum+= ((float)i/fac);
    }
    printf("%f", sum);
    return 0;

}