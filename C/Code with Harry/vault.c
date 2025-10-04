#include <stdio.h>
#include <stdbool.h>
bool isPrime(long long int n)
{
    if (n < 2)
        return false;
    for (long long int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n ;
    long long int sum;
    scanf("%d", &n);
    while (1)
    {
        long long int fac = 1;
        sum = 0;

        for (int i = 1; i <= n; i++)
        {
            fac *= i;
            bool prim = isPrime(fac);
            bool ends4 = fac % 10 == 4;
            bool ends6 = fac % 10 == 6;
            bool ends0 = fac % 10 == 0;

            if (fac == 1 || prim || ends4 || ends6 || ends0)
            {
                sum += fac;
            }
        }

        if ((sum % 4 == 0 && sum % 100 != 0) || (sum % 100 == 0 && (sum / 100) % 4 == 0))
            n++;
        else
            break;
    }

    printf("%lld\n", sum);
    return 0;
}