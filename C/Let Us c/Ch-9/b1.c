#include <stdio.h>

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[5] = {44, 33, 55, 22, 11};
    // selection_sort(a,5);
    // bubble_sort(a, 5);
    insertion_sort(a,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}