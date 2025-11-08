#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    char plain, cipher;
    char word1[20], word2[20];
    char line[100];
    char plainArr[26], cipherArr[26];
    int i = 0;

    fp = fopen("cipher.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Skip the header lines
    fgets(line, sizeof(line), fp);  // "SUBSTITUTION CIPHER MAPPING (A–Z)"
    fgets(line, sizeof(line), fp);  // "----------------------------------"
    fscanf(fp, "%s %s", word1, word2); // "PLAIN CIPHER"
    fgets(line, sizeof(line), fp);  // move to next line
    fgets(line, sizeof(line), fp);  // skip dashed line

    // Read the mapping lines
    while (fscanf(fp, " %c %c", &plain, &cipher) == 2)
    {
        plainArr[i] = plain;
        cipherArr[i] = cipher;
        i++;
    }
    fclose(fp);

    // Input string to encrypt
    char text[200];
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin); // consume leftover newline
    fgets(text, sizeof(text), stdin);

    // Encrypt
    char encrypted[200];
    strcpy(encrypted, text);
    for (int j = 0; text[j] != '\0'; j++)
    {
        char ch = text[j];
        if (isalpha(ch))
        {
            ch = toupper(ch);
            for (int k = 0; k < 26; k++)
            {
                if (plainArr[k] == ch)
                {
                    encrypted[j] = cipherArr[k];
                    break;
                }
            }
        }
        else
            encrypted[j] = text[j];
    }
    encrypted[strlen(text)] = '\0';

    printf("\nEncrypted: %s\n", encrypted);

    // Decrypt
    char decrypted[200];
    strcpy(decrypted, encrypted);
    for (int j = 0; encrypted[j] != '\0'; j++)
    {
        char ch = encrypted[j];
        if (isalpha(ch))
        {
            ch = toupper(ch);
            for (int k = 0; k < 26; k++)
            {
                if (cipherArr[k] == ch)
                {
                    decrypted[j] = plainArr[k];
                    break;
                }
            }
        }
        else
            decrypted[j] = encrypted[j];
    }
    decrypted[strlen(encrypted)] = '\0';

    printf("Decrypted: %s\n", decrypted);

    return 0;
}
