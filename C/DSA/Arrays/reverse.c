#include<stdio.h>

void rev_1(int a[], int n){
    for(int i=0;i<n/2;i++){
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    return;
}

void rev_2(int a[], int n){
    int *start=&a[0];
    int *end=&a[n-1];
    while(start < end){
        int temp= *start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
    return;
}

void rev_3(int a[], int start, int end){
    if(start>=end) return;
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    rev_3(a,start+1,end-1);
}