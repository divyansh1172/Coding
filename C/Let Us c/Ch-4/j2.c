#include<stdio.h>

int main()
{
    for (int y = 1; y <= 6; y++)
    {
        for (float x =5.5; x<=12.5; x+=0.5)
        {
            printf("i = %.2f, for x=%.1f , y=%d\n", 2+y+ 0.5*x, x,y);
        }
        
    }
    return 0;

}