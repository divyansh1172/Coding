#include<stdio.h>

int main()
{
    int num, rev_num,n;
    printf("Please enter a 5-digit number:  ");
    scanf("%d",&num);
    n=num;

    rev_num=0;
    for(int i=0;i<5;i++)
    {
        rev_num=rev_num*10 + n%10;
        n/=10;
    }
    printf("%d\n",rev_num); 
    if (rev_num==num)
    {
        printf("The rev num and og num are equal \n");
    }

    else
        printf("Not equal\n");
    
    return 0;
}