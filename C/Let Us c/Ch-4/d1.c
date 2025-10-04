#include<stdio.h>
int main()
{
    int i=0;
    while(i<256)
    {
        printf("%c %d\n", (char)i, i);
        i++;
    }
    return 0;
}