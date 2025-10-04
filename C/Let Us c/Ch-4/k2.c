#include<stdio.h>
#include<math.h>
int main()
{
    int i=1;
    int n, q, p;
    float r;
    double a;
    while(i<=10)
    {
        printf("PLease enter p, r, n,q:");
        scanf("%d %f %d %d", &p, &r, &n, &q);
        double k=1 + r/q;
        a=p* pow(k, n*q);
        printf("The a is : %.2lf\n", a);
        i++;
    }
    return 0;
}