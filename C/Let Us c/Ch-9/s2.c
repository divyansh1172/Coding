#include <stdio.h>

int main()
{
    int s[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        int check[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int j = 0; j < 9; j++)
        {
            check[s[i][j] - 1]--;
            if (check[s[i][j] - 1] != 0)
            {
                printf("incorrect solution.\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        int check[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int j = 0; j < 9; j++)
        {
            check[s[j][i] - 1]--;
            if (check[s[j][i] - 1] != 0)
            {
                printf("incorrect solution.\n");
                return 0;
            }
        }
    }

    for (int boxRow = 0; boxRow < 9; boxRow += 3)
    {
        for (int boxCol = 0; boxCol < 9; boxCol += 3)
        {
            int check[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
            for (int i = boxRow; i < boxRow + 3; i++)
            {
                for (int j = boxCol; j < boxCol + 3; j++)
                {
                    check[s[i][j] - 1]--;
                    if (check[s[i][j] - 1] != 0)
                    {
                        printf("incorrect solution.\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("correct solution\n");
    return 0;
}