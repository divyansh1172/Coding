#include<stdio.h>
int main()
{
    char i='y';int n=0 ,pos=0, neg=0, zer=0;
    while(i=='y')
    {
        printf("ENter a number :  ");
        scanf("%d", &n);
        if(n>0) pos++;
        else if(n<0) neg++;
        else zer++;

        printf("Do u wanna continue: (y/n)");
        scanf(" %c", &i);
    }

    printf("The number of positive number: %d\n", pos);
    printf("The number of negative number: %d\n", neg);
    printf("The number of zeros: %d\n",zer);
    return 0;
}