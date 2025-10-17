#include<stdio.h>

void transform(int a[], int n)
{
    for(int i=0; i<n-1; i+=2)
    {
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
}

int main()
{
    int a[25];
    for(int i=0;i<25; i++)
    {
        a[i]=i+1;
    }
    transform(a,25);
    for(int i=0;i<25; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}