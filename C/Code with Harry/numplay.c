#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long long n)
{
    if (n < 2)
        return false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long largestPrimeFactor(long long n)
{
    long long maxPrime = -1;
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n /= i;
        }
    }
    if (n > 2)
        maxPrime = n;
    return maxPrime;
}

long long f(long long x)
{
    long long val = 2 * x + 1;
    if (isPrime(val))
        return val;
    return largestPrimeFactor(x);
}

long long g(long long x)
{
    if (x % 4 < 2)
        return (x * x * x + 11) % 3;

    else
        return (x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x - 8) % 5;
}

