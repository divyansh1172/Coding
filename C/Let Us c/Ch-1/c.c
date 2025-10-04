#include <stdio.h>

int main()
{
    int l[9], b[9];
    l[0] = 1189;
    b[0] = 841;

    for (int i = 0; i < 8; i++)  // Loop up to i = 7
    {
        if (l[i] > b[i])
        {
            l[i + 1] = l[i] / 2;
            b[i + 1] = b[i];
        }
        else if (l[i] < b[i])
        {
            b[i + 1] = b[i] / 2;
            l[i + 1] = l[i];
        }
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%d x %d\n", l[i], b[i]);
    }

    return 0;
}
