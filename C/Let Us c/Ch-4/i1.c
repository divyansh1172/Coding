#include<stdio.h>
int main()
{
    int max=0, min=0, n;
    char k='Y';int first=1;
    while(k=='Y'||k=='y')
    {
        scanf("%d", &n);
        if(first)
        {
            min=n;max=n;
            first =0;
        }

        if(n>max)
        {
            max=n;
        }
        else if(n<min)
        {
            min=n;
        }
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &k);
    }
    printf("The range of the given data is %d", max-min);
    return 0;
}