#include <stdio.h>

void transform_array(int a[], int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            int k = 2 * a[i];
            for (int m = k - 1; m < n; m += a[i])
            {
                a[m] = 0;
            }
        }
    }
}

void print_transformed_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            printf("%d\n", a[i]);
        }
    }
}

int main()
{
    int nums[100];
    for (int i = 0; i < 100; i++)
    {
        nums[i] = i + 1;
    }
    int n = 100;
    transform_array(nums, n);
    print_transformed_array(nums, n);
    return 0;
}