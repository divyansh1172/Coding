#include<stdio.h>

int main()
{
    int maths, eng, sst, sci, hin;
    printf("please enter all your marks:  \n");
    scanf("%d",&maths);
    scanf("%d",&eng);
    scanf("%d",&sst);
    scanf("%d",&sci);
    scanf("%d",&hin);
    float perc;
    perc=(maths+eng+sst+sci+hin)/5;
    printf("%.2f \n",perc);
    return 0;
}