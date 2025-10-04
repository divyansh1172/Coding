#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d", &n);
    int rows;
    rows=2*n-1;
    
    for(int i=1;i<= rows  ; i++)
    {
        if(i>n)
        { 
            m=2*n-i;
        }
        else 
        {
            m=i;
        }
        
        for(int j=1;j<=n-m;j++)
        {
            printf("  ");
        }
        if(m%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                if(j==m)
                {
                    printf(" ");
                }
                printf("%2d",j);
                if(j>1) printf(" ");
            }
            for(int j=2;j<=m;j++)
            {
                printf(" %2d",j);
            }
        }
        
        else
        {
            for(int j=64+m;j>=65;j--)
            {
                if(j==m+64) printf(" ");
                printf("%2c",(char)j);
                if(j>65) printf(" ");
            }
            for(int j=66;j<=m+64;j++)
            {
                
                printf(" %c",(char)j);
            }
        }
        printf("\n");
    }
    return 0;
}