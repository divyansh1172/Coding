#include <stdio.h>

// int prime(int n)
// {
//     if (n < 2)
//         return 0;
//     if (n == 2)
//         return 1;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return 0;
//     }
//     return 1;
// }

void prime_factors(int n)
{
    int factors[100], count = 0;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[count++] = i;
            n /= i;
        }
    }

    // If n is still greater than 1, then n itself is a prime factor
    if (n > 1)
    {
        factors[count++] = n;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", factors[i]);
    }
    printf("\n");
}

int main()
{
    int n = 24;
    prime_factors(n);
    return 0;
}
