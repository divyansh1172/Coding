#include <stdio.h>

int rec_sum(int n)
{
    if (n == 1)
        return 1;

    return n + rec_sum(n - 1);
}
int main()
{
    for (int i = 1; i < 26; i++)
    {
        printf("The sum till %d is %d\n", i, rec_sum(i));
    }
    return 0;
}