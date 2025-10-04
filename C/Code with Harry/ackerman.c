#include <stdio.h>

int main()
{
    long long int n, k;
    int digits_num = 0, count = 0;
    scanf("%lld %lld", &n, &k);

    int digs[21];
    long long int m = n;

    // count digits
    while (m > 0)
    {
        digits_num++;
        m /= 10;
    }

    // extract digits in correct order
    m = n;
    for (int i = digits_num - 1; i >= 0; i--)
    {
        digs[i] = m % 10;
        m /= 10;
    }

    // try all sub-arrays
    for (int i=0; i< digits_num; i++) // starting index
    {
        int sum=0;
        for(int j=i;j<=digits_num;j++) // ending index
        {
            sum+=digs[j-1];
            if (sum<=k)
            {   
                count++;
            }
            
        }
    }

    printf("%d\n", count);
    return 0;
}