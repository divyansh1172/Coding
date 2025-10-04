#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool Armstrong_number(int n)
{
    int sum=0, a=n, dig=0;
    while(a)
    {
        dig++;
        a/=10;
    }
    a=n;
    while(a)
    {
        sum+= pow(a%10, dig);
        a/=10;
    }
    return sum==n;
}

int main()
{
    int i=1;
    while(i<=500)
    {
        if(Armstrong_number(i))
        {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}