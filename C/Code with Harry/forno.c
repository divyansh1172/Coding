#include<stdio.h>
#include<math.h>

int main()
{
    int x;
    scanf("%d", &x);
    int n=x,digs=0;
    while(n>0)
    {
        digs++;
        n/=10;
    }
    int dig[20];
    n=x;
    for(int m=digs-1;m>=0;m--)
    {
        dig[m]=n%10;
        n/=10;
    }
    int sum=0;
    for (int i = 0; i < digs; i++)
    {
        sum+=pow(dig[i],digs);
    }
    
    if(sum==x)
    {
        printf("FORBIDDEN NUMBER!!!!");
    }
    else
    {
        printf("NOt one");
    }
    return 0;

}