#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// function prototype
bool isColorCorrect(char *coordinates, char *color);
int main()
{
    char coordinates[3], color[10];
    scanf("%s %s", coordinates, color);

    if (isColorCorrect(coordinates, color))
        printf(" true \n");
    else
        printf(" false \n");

    return 0;
}
// complete the following function
bool isColorCorrect(char *coordinates, char *color)
{
    int k=*coordinates - 'a';
    int m= *(coordinates+1) - '1';

    if((k+m)%2 == 0 && strcmp(color, "black")==0) return true;
    else if((k+m)%2 == 1 && strcmp(color, "white")==0) return true;

    return false;
}