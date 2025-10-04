#include<stdio.h>

int sum_digs(int n)
{
    int sum=0;
    while(n)
    {
        sum+= n%10;
        n/=10;
    }
    return sum;
}

int rec_sum_digs(int n)
{
    if(n<10) return n;

    else 
    return n%10 + rec_sum_digs(n/10);
}

int main()
{
    int n=123456789;
    printf("The sum using sum_digs=%d\n", sum_digs(n));
    printf("The sum using rec_sum_digs=%d\n", rec_sum_digs(n));
    return 0;
}