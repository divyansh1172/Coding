#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n], arr1[n];
    arr[0]=1;
    for (int  i = 1; i < n; i++)
    {
        arr[i]=0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for(int j=0; j<5; j++)
        {
            arr1[j]=arr[j];
        }
        for (int j = n - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i - 1; j++)
        {
            if (j == 0)
            {
                printf("1 ");continue;
            }
            
            else if (j!= i-1)
            {
                arr[j] =arr[j] +arr1[j -1];
                printf("%d ", arr[j]);
                continue;
            }
            else
            {
                arr[j]=1;
                printf("1 ");
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}