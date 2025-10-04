#include <stdio.h>

void rhombus(int n)
{
    int rows = 2 * n - 1;
    int m;
    for (int i = 1; i <= rows; i++)
    {
        if(i<=n) m=i;
        else m=2*n-i;

        for(int j=0; j<n-m;j++)
        {
            printf(" ");
        }

        for(int j=m; j>=1; j--)
        {
            printf("%1d",j);
        }
        for(int j=2; j<=m; j++)
        {
            printf("%1d",j);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    rhombus(n);
    return 0;
}