#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n - 2; i++)
    {
        scanf("%d", &arr[i]);
    }
    bool k[n];
    for (int i = 0; i < n; i++)
    {
        k[i] = false;
    }

    for (int j = 0; j < n - 2; j++)
    {
        k[arr[j] - 1] = true;
    }

    for(int i=0;i<n;i++)
    {
        if(!(k[i]))
        {
            printf("%d ",i+1);
        }
    }
    printf("\n");
    
    return 0;


}