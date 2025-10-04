#include <stdio.h>
int main()
{
    int prime;
    printf("2\n");
    for (int i = 3; i <= 300; i++)
    {
        prime=1;
        for (int j = 2; j*j <=i; j++)
        {
            if(i%j==0)
            {
                prime =0;
                break;
            }
        }
        if(prime)
            printf("%d\n",i);
        
    }
    return 0;
}