// Prefix Sum
// Calculating the sum of all the elements upto ith elem to give the range-sum query result in O(1) time
#include<stdio.h>

int *PrefixSum(int a[], int n){
    int *res=(int *)malloc(n*sizeof(int));
    res[0]=a[0];
    for(int i=1;i<n;i++) res[i] = res[i-1]+a[i];
    return res;
}