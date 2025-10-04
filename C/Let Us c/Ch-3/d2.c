#include<stdio.h>
int main()
{
    int day=0;
    float sum=0;
    int done=0;
    scanf("%d", &day);  
    if(day<=5)
    {
        sum+=(float)day/2.0;
    }
    else if(day>=5)
    {
        sum+= 2.5; done=5;

        if(day>5 && day<10)
        {
            sum+= (day-done)*1;
        }
        else
        {
            sum+= 5; done=10;

            if(day>10)
            {
                sum+=(day-10)*5;
            }

        }

    }
    printf("%.1f\n", sum);

    if(day>30)
    {
        printf("Membership cancelled \n");
    }

    return 0;

}