#include <stdio.h>

void rev_an_array(int start, int end, int *a)
{
    while (start<end)
    {
        int temp=*(a+start);
        *(a+start)= *(a+end);
        *(a+end)=temp;
        start++;
        end--;
    }
}
void transform(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; i++)
    {
        //for any arbritray m do m%n first then change the given condition in the shit
        rev_an_array(0, 1, &a[i][0]);
        rev_an_array(2, n - 1, &a[i][0]);
        rev_an_array(0, n - 1, &a[i][0]);
    }
}

int main()
{
    int a[4][5];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    transform(4,5,a);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}