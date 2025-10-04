#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);

    int rev_num=0;
    while(x>0)
    {
        rev_num=rev_num*10 + x%10;
        x/=10;
    }
    printf("%d\n",rev_num);
    return 0;
}