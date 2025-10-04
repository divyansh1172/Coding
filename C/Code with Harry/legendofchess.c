#include<stdio.h>

int main()
{
    unsigned long int n, power=1, sum=0;
    int k=0;
    scanf("%lu",&n);
    for (int i = 1; i < 50; i++)
    {
        if(sum+ power <=n)
        {
            k++;
            sum+=power; 
            power*=2;
        }
        else
        {
            break;
        }
    }
    
    if(k==49)
    {
        printf("YES\n%lu\n",n-sum);
    }

    else
    {
        printf("NO\n%d\n",k);
    }

    return 0;

}