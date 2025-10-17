
#include <stdio.h>

void display(int *q, int, int);
void show(int (*q)[4], int, int);
void print(int q[][4], int, int);

int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 6}};

    display(&a[0][0], 3, 4);
    show(a, 3, 4);
    print(a,3,4);

    return 0;
}

void display(int *q, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(q + j + i * n));
        }
        printf("\n");
    }
    printf("\n");
}

void show(int (*q)[4], int m, int n)
{
    
    for (int i = 0; i < m; i++)
    {
        int *p = *(q + i);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(p + j));
        }
        printf("\n");
    }
    printf("\n");
}

void print(int a[][4], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}