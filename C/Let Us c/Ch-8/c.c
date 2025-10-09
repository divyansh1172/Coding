#include<stdio.h>

#include "areaperi.h"

int main()
{
    printf("%d\n", peri_tri(1,2,3));
    printf("%d\n", peri_squ(1));
    printf("%.2lf\n", peri_circ(2));
    printf("%.2lf\n", area_tri(1,2,3));
    printf("%.2lf\n", area_squ(1.5));
    printf("%.2lf\n", area_circ(2));
    return 0;
}