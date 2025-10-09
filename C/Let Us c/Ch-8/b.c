#include <stdio.h>
#include <stdbool.h>

#define small(c) ((c >= 'a' && c <= 'z') ? true : false)
#define upper(c) ((c >= 'A' && c <= 'Z') ? true : false)
#define alpha(c) ((small(c) && upper(c)) ? true : false)
#define larger(a, b) (a > b ? a : b)

int main()
{
    printf("%d\n", small('a') );
    printf("%d\n", small('A') );
    printf("%d\n", upper('a') );
    printf("%d\n", upper('A') );
    printf("%d\n", alpha('A') );
    printf("%d\n", alpha('1') );
    printf("%d\n", larger(2,3));
    return 0;
}