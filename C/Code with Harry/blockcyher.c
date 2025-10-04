#include <stdio.h>

int main()
{
    unsigned long int n, a, pow10 = 1;
    int k;
    scanf("%lu %d", &n, &k);
    a = n;
    int blocks;
    int digs=0;
    while (a > 0)
    {
        digs++;
        a /= 10;
    }
    a = n;

    for (int i = 0; i < k; i++)
    {
        pow10 *= 10;
    }

    if (digs % k == 0)
        blocks = digs / k;
    else
        blocks = digs / k + 1;

    unsigned long int b[blocks];
    for (int i = blocks - 1; i >= 0; i--)
    {
        b[i] = a % pow10;
        a /= pow10;
    }

    for (int i = 0; i < blocks; i++)
    {
        b[i] += b[i] % 10;
        b[i] %= pow10;
    }
    printf("%d\n", blocks);
    for (int i = 0; i < blocks; i++)
    {
        if (i == 0)
            printf("%lu", b[i]);
        else
            printf("%0*lu", k, b[i]);
    }

    return 0;
}