#include<stdio.h>
int main()
{
    int i=1, hr;
    while(i<=10)
    {
        printf("Please enter the number of hours you have worked:\t");
        scanf("%d", &hr);
        if(hr>40)
        {
            printf("Overtime= %d \n", (hr-40)*12);
        }
        else
        {
            printf("No overtime\n");
        }
        i++;
    }
    return 0;

}