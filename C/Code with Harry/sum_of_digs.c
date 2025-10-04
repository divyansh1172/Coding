#include<stdio.h>

int sum(int n)
{
    if(n/10==0) return n;

    else
    {
        return n%10 + sum(n/10);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int sum_digs=sum(n);

    printf("%d", sum_digs);
    return 0;
}