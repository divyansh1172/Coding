#include<stdio.h>
int main()
{
    int hard, ts;
    float cc;
    printf("Please enter Hardness:\t");
    scanf("%d", &hard);
    printf("Please enter Carbon content:\t");
    scanf("%f", &cc);
    printf("Please enter Tensil strength:\t");
    scanf("%d", &ts);

    if(hard>50 && cc < 0.7 && ts>5600) printf("Grade 10\n");

    else if(hard>50 && cc < 0.7 ) printf("Grade 9\n");

    else if(cc < 0.7 && ts>5600) printf("Grade 8\n");

    else if(hard>50 && ts>5600) printf("Grade 7\n");

    else if(hard>50 || cc < 0.7 || ts>5600) printf("Grade 6\n");

    else  printf("Grade 5\n");

    return 0;
}