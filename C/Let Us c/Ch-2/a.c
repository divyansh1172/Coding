#include<stdio.h>
int main()
{
    printf("Please enter a 5-digit number:  \n");
    int x;
    scanf("%d",&x);

    int sum=0;
    while(x>0)
    {
        sum+=x%10;
        x/=10;
    }

    printf("%d", sum);
    return 0;
}