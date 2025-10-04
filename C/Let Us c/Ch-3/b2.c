#include<stdio.h>
int main()
{
    char c;
    scanf("%c", &c);

    if(c>=65 && c<=90) printf("Uppercase\n");

    else if(c>=97 && c<=122) printf("lowercase\n");

    else if(c>=48 && c<=57) printf("Digit\n");

    else printf("Special char \n");

    return 0;
    
}