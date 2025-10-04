#include<stdio.h>

int main()
{
    int a,b,c;
    printf("Please enter the angle a in degrees:  ");
    scanf("%d",&a);
    printf("Please enter the angle b in degrees:  ");
    scanf("%d",&b);
    printf("Please enter the angle c in degrees:  ");
    scanf("%d",&c);

    if((a+b+c)==180 )
    {
        printf("ABC is a triangle: \n");
    }
    else
        printf("ABC is not a triangle\n");

    return 0;

}