#include<stdio.h>
int main()
{
    int n=21;
    while(n)
    {
        int i;
        printf("Players turn: ");
        scanf("%d", &i);
        n-=i;
        if(n==1)
        {
            printf("Computer loses\n");
            break;
        }
        printf("COmp chooses %d", i);
        n-=i;
        if(n==1)
        {
            printf("PLayer loses\n"); break;
        }
        printf("\nRemaining matchsticks are %d\n", n);
    }
    return 0;
}