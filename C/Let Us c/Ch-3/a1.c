#include<stdio.h>
int main()
{
    float cp, sp, diff;
    printf("Please enter the cost price an dselling price of the item:\n");
    scanf("%f %f", &cp, &sp);

    diff=sp-cp;
    if(diff>0)
    {
        printf("The shopkeeper got a profit of %.2f", diff);
    }

    else
    {

        diff=-diff;
        printf("The shopkeeper incurred a loss of %.2f", diff);
    }
    return 0;   
}         