#include <stdio.h>
#include <math.h> // Required for the sqrt function

int main() {
    int a, b, c_squared;
    double c_double;
    int limit = 30;

    printf("Pythagorean Triples with side length less than or equal to %d:\n", limit);

    // Iterate through possible values for 'a'
    for (a = 1; a <= limit; a++) {
        // Iterate through possible values for 'b', ensuring b >= a to avoid duplicates and redundant checks
        for (b = a; b <= limit; b++) {
            // Calculate c_squared (a^2 + b^2)
            c_squared = a * a + b * b;

            // Calculate the square root of c_squared
            c_double = sqrt(c_squared);

            // Check if c_double is an integer and within the limit
            // (c_double == (int)c_double) checks if it's a whole number
            if (c_double == (int)c_double && (int)c_double <= limit) {
                printf("(%d, %d, %d)\n", a, b, (int)c_double);
            }
        }
    }

    return 0;
}