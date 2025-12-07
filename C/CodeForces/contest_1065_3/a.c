#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int n;
    while(t--)
    {
        scanf("%d", &n);
        if(n==0) {printf("1\n"); continue;}
        int count=0; // number of different possible outcomes;
        // int k=n;
        if(n%2==1){printf("0\n"); continue;}
        for(int i=0; i<=n/2; i++)   {if((n-2*i)%4 == 0) count++;}
        printf("%d\n", count);
    }
    return 0;
}