#include <stdio.h>

void change(char *a, char *map, char *cip)
{
    if (*a == ' ')
    {
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (*a == cip[i])
        {
            *a = map[i];
            return;
        }
    }
    return;
}

int main()
{
    FILE *fp = fopen("mappingEE25BTECH11037.txt", "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file.\n");
        fclose(fp);
        return 1;
    }

    char text[50], dash1[50], dash2[50], text2[100];
    fgets(text, sizeof(text), fp);
    fgets(dash1, sizeof(dash1), fp);
    fgets(text2, sizeof(text2), fp);
    fgets(dash2, sizeof(dash2), fp);

    char cipher[30], plain[30], line[20];
    for (int i = 0; i < 26; i++)
    {
        fgets(line, sizeof(line), fp);
        plain[i] = line[0];
        cipher[i] = line[10];
        // fscanf(fp, "%c %c", &plain[i], &cipher[i]);
    }

    fclose(fp);
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%c %c\n", plain[i], cipher[i]);
    // }

    char a;
    FILE *cyp = fopen("cipherEE25BTECH11037.txt", "r");
    if (cyp == NULL)
        printf("Error: cannot open file.\n");
    FILE *new = fopen("EE25BTECH11037.txt", "w");
    a = fgetc(cyp);
    while (a != EOF)
    {
        change(&a, plain, cipher);
        fputc(a, new);
        // fprintf(new, "%c", a);
        a = fgetc(cyp);
    }

    fclose(new);
    fclose(cyp);
    return 0;
}