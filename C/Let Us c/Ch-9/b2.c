#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int m[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    int max=m[0][0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(m[i][j]>max)
            {
                max=m[i][j];
            }
        }
    }
    printf("%d\n",max);
    return 0;
}