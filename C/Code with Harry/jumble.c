#include <stdio.h>

// Bubble sort for char arrays
void arrange_arr(char arr[], int len)
{
    for (int pass = 0; pass < len - 1; pass++)
    {
        for (int i = 0; i < len - 1 - pass; i++) // optimization
        {
            if (arr[i] < arr[i + 1]) // descending order
            {
                char temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    char string[500], word1[250], word2[250];
    scanf("%[^\n]", string);

    int i = 0, j = 0, k = 0;

    // extract first word
    while (string[i] != ' ' && string[i] != '\0')
    {
        word1[j++] = string[i++];
    }
    word1[j] = '\0';

    if (string[i] == ' ')
        i++; // skip space

    // extract second word
    while (string[i] != '\0')
    {
        word2[k++] = string[i++];
    }
    word2[k] = '\0';

    // if lengths differ → not jumbles
    if (j != k)
    {
        printf("no");
        return 0;
    }

    // sort both words
    arrange_arr(word1, j);
    arrange_arr(word2, k);

    // compare manually
    int same = 1;
    for (int x = 0; x < j; x++)
    {
        if (word1[x] != word2[x])
        {
            same = 0;
            break;
        }
    }

    if (same)
        printf("yes");
    else
        printf("no");

    return 0;
}