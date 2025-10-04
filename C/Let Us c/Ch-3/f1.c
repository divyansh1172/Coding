#include<stdio.h>

int main()
{
    int ram, shyam, ajay;
    printf("Please enter age of Ram: ");
    scanf("%d", &ram);

    printf("Please enter age of Shyam: ");
    scanf("%d", &shyam);

    printf("Please enter age of Ajay: ");
    scanf("%d", &ajay);

    if (ram <= shyam && ram <= ajay)
        printf("Ram is youngest\n");
    else if (shyam <= ram && shyam <= ajay)
        printf("Shyam is youngest\n");
    else
        printf("Ajay is youngest\n");

    return 0;
}
