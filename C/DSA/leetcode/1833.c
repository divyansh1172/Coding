#include<stdio.h>
#include<stdlib.h>

int maxIceCream(int* costs, int costsSize, int coins) {
    int *count = calloc(coins+1, sizeof(int));
    int cnt=0;
    for(int i=0;i<costsSize; i++)
        count[i]++;
    for(int i=1;i<coins+1;i++){
        while(count[i]--) cnt++;
    }
    return cnt;
}

