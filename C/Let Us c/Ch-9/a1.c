#include<stdio.h>

int main()
{
    int a[25];
    for (int i = 0; i < 25; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Please enter the number to be searched :    ");
    int k;
    scanf("%d", &k);
    int count =0;
    for (int i = 0; i < 25; i++)
    {
       if(a[i] == k) count++; 
    }
    if(count) printf("found %d\n", count);
    else printf("nope");
    return 0;   
}