#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c,s,area, x;
    printf("please enter the three sides of the triangle:   ");
    scanf("%f%f%f",&a,&b,&c);
    s=(a+b+c)/2;
    x=s*(s-a)*(s-b)*(s-c);
    area=sqrt(x);

    printf("The area of the given triangle is %.2f\n", area);
    return 0;
    
}