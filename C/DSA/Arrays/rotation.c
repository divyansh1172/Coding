#include<stdio.h>

void rev_3(int a[], int start, int end){
    if(start>=end) return;
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    rev_3(a,start+1,end-1);
}

// rotating to left
// reverse the first k elems and then the remainng n-k elems, and then again reverse the whole array again
void rotate_l(int a[], int n, int k){
    if (k==0) return;
    
    k%=n;
    rev_3(a,0, k-1);
    rev_3(a,k,n-1);
    rev_3(a,0,n-1);
    return;
}

// rotating to right
// reverse the whole array first and then reverse the first k elems and then n-k elems
void rotate_r(int a[], int n, int k){
    if(k==0)return;
    k%=n;
    
    rev_3(a,0,n-1);
    rev_3(a,0, k-1);
    rev_3(a,k,n-1);
}