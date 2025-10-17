#include<stdio.h>

void mult_2_mats(int m, int a[m][m], int b[m][m], int c[m][m])
{
    for(int i=0; i<m ;i++)
    {
        for (int  j = 0; j < m; j++)
        {
            c[i][j]=0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main()
{
    int a[3][3],b[3][3];
    int k=1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j]=k;
            k++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i==j) b[i][j]=1;
            else b[i][j]=0;
        }
    }

    int c[3][3];
    mult_2_mats(3, a,b,c);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j] );
        }
        printf("\n");
    }
    return 0;
}