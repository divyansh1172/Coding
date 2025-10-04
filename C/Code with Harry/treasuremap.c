#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if(i>=k)
        {
            arr2[i]=arr1[i-k];
        }
        else
        {
            arr2[i]=arr1[i-k+n];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}