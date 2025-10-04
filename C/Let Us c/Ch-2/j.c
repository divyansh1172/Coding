#include<stdio.h>
#include<math.h>

int main()
{
    float temp, wind_velo, wcf;

    printf("Please enter temperature:\n");
    scanf("%f", &temp);

    printf("Please enter wind velocity:\n");
    scanf("%f", &wind_velo);

    wcf = 35.74 + 0.6215*temp + (0.4275*temp - 35.75)* pow(wind_velo,0.16);

    printf("the wind chill factor is %.2f\n", wcf);
    return 0;
}