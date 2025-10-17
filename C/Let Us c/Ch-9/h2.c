#include<stdio.h>

// int check_if_symmetric(int m, int a[m][m])
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = i+1; j < m; j++)
//         {
//             if (a[i][j]!=a[j][i])
//             {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
int check_if_symmetric(int m, int *a)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (*(*(a+i)+j)!=*(*(a+j)+i))
            {
                return 0;
            }
        }
    }
    return 1;
}
1 8 0 7 3 1
8 3 1 8 0 9
0 1 2 2 2 3
7 8 2 5 7 0
3 0 2 7 3 1
1 9 3 0 1 2
int main()
{
    int a[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if (check_if_symmetric(6,&a[0][0]))
    {
        printf("Yes\n");
    }
    else printf("No\n");
    return 0;
}