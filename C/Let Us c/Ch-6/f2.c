#include <stdio.h>

int binary(int n, int a[])
{
    int count = 0;
    while (n)
    {
        a[count++] = n % 2;
        n /= 2;
    }
    for (int i = 0; i < count / 2; i++)
    {
        int temp = a[i];
        a[i] = a[count - i - 1];
        a[count - i - 1] = temp;
    }
    return count;
}
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return;
}

void binary_rec(int n, int *p)
{
    if (n)
    {
        *(p++) = n % 2;
        binary_rec(n / 2, p);
    }
    return;
}
int main()
{
    int n = 64;
    int a[100];
    int count = binary(n, a);
    // print_array(a, count);
    for (int i = 0; i < count; i++)
    {
        a[i]=0;
    }
    
    binary_rec(n,a);
    
    for (int i = 0; i < count/2; i++)
    {
        int temp = a[i];
        a[i] = a[count - i - 1];
        a[count - i - 1] = temp;
    }
    print_array(a, count);
    return 0;
}