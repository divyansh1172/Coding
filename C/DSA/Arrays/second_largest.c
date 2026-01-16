#include<stdio.h>
#include<limits.h>

int second_largest(int a[], int n){
    if(n<2) return -1;
    int max_1=INT_MIN;
    int max2=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max_1){
            max2=max_1;
            max_1=a[i];
        }
        else if(a[i]>max2 && a[i]!=max_1){
            max2=a[i];
        }
    }
    return max2;
}