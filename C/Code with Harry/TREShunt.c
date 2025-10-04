#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int freq[101] = {0}; // frequency array (assumes numbers ≤ 100)

    // Count frequencies
    for (i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Print in increasing order
    for (i = 0; i < 101; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d : %d\n", i, freq[i]);
        }
    }

    return 0;
}
