#include<stdio.h>

int main()
{
    int num,new_num=0, place_value=1;
    printf("Please enter a 5 digit number:   ");
    scanf("%d",&num);
    // org_num=num;

    int dig;

    for (int i = 0; i < 5; i++)
    {
        dig=num%10;

        dig++;

        new_num+=dig*place_value;
        num/=10;
        place_value*=10;
    }
    
    printf("%d\n",new_num);
    return 0;
}