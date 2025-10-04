#include <stdio.h>

void sort_array(int items[], int freq[], int n)
{
    int count = n;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if ((freq[items[i]] < freq[items[j]]) || (freq[items[i]] == freq[items[j]] && items[i] > items[j]))
            {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int items[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    int freq[101] = {0};
    for (int i = 0; i < 100; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[items[i]]++;
    }

    sort_array(items, freq, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", items[i]);
    }
    printf("\n");
    return 0;
}