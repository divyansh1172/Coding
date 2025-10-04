#include <stdio.h>

void circle(int *a, int *b, int *c)
{
    int temp = *c;
    *c = *b;
    *b = *a;
    *a =temp;
}

int main()
{
    int a, b, c;
    a = 5;
    b = 8;
    c = 10;
    printf("%d %d %d\n", a, b, c);
    circle(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}