#include <stdio.h>

int inner_prod(int r, int c, int A[r][c], int B[r][c])
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += A[i][j] * B[i][j];
        }
    }
    return sum;
}
int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int A[r][c], B[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    int prod = inner_prod(r, c, A, B);
    printf("%d", prod);
    return 0;
}