#include<stdio.h>

void things(int a[3], float* avg, float* perc)
{
    int sum=0;
    for (int i = 0; i < 3; i++)
    {
        sum+=a[i];
    }
    *avg=sum/3;
    *perc=*avg;
}

int main()
{
    int a[3], b[3], c[3];
    float avg, perc;
    things(a, &avg, &perc);
    things(b, &avg, &perc);
    things(c, &avg, &perc);
    return 0;
}