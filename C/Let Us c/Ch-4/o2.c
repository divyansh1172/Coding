#include <stdio.h>

#define LIMIT 100000

int main() {
    int a, b, c, d;
    int sum1, sum2;

    printf("Ramanujan numbers up to %d are:\n", LIMIT);

    for (a = 1; a * a * a < LIMIT; a++) {
        for (b = a; a * a * a + b * b * b < LIMIT; b++) {
            sum1 = a*a*a + b*b*b;

            for (c = a + 1; c * c * c < LIMIT; c++) {
                for (d = c; c*c*c + d*d*d < LIMIT; d++) {
                    sum2 = c*c*c + d*d*d;

                    if (sum1 == sum2) {
                        printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", sum1, a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}
