#include <stdio.h>

long long int factorial(int a)
{
    long long int fac = 1;
    for (int i = 1; i <= a; i++)
        fac *= i;
    return fac;
}

void prime_or_not(int a)
{
    if (a == 1) {
        printf("1 is not a prime\n");
        return;
    }

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            printf("%d is not a prime\n", a);
            return;
        }
    }
    printf("%d is a prime\n", a);
}

void Odd_or_even(int a)
{
    if (a % 2 == 0)
        printf("%d is even\n", a);
    else
        printf("%d is odd\n", a);
}

int main()
{
    int k;
    while (1)
    {
        printf("Please choose your option:\n1. Factorial\n2. Prime or not\n3. Odd or even\n4. Exit\n");
        scanf("%d", &k);

        int a;
        if (k != 4)
        {
            printf("Please choose a number:\n");
            scanf("%d", &a);
        }

        switch (k)
        {
        case 1:
            printf("Factorial of %d is %lld\n", a, factorial(a));
            break;

        case 2:
            prime_or_not(a);
            break;

        case 3:
            Odd_or_even(a);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}
