#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100], i=0;
    while(n)
    {
        arr[i]=n%8;i++;
        n/=8;
    }
    
    int count=i-1;
    while(count>=0)
    {
        printf("%d", arr[count]);
        count--;
    }
    
    return 0;
}