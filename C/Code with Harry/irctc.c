#include<stdio.h>
int main()
{
    unsigned short int age;
    scanf("%hu",&age);
    int cost;
    if(age<=2) cost=0;

    else if(age>2 && age<=12) cost=490;

    else if(age>=65) cost=510;
    
    else cost=1000;

    printf("%d\n\n",cost);
    return 0;
}