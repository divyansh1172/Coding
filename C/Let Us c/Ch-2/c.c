#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);

    int sum;
    sum = x%10 + x/1000;
    printf("%d\n",sum);
    return 0;
}