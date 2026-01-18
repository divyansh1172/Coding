// Dutch National Flag Pattern
// Used for sorting array with only three types of elems
// assuming there are only three - 0,1,2
#include<stdio.h>

void sort_Dutch(int a[], int n){
    // low is to insert the zero, mid is the elem being checked, and topp is to insert the 2
    int low=0, mid=0, top=n-1;
    while(mid <= top){
        if(a[mid]==0){
            int temp=a[low];
            a[low++]=a[mid];
            a[mid++]=temp;
        }
        else if(a[mid]==1){mid ++; continue;}
        else{
            int temp=a[top];
            a[top--]=a[mid];
            a[mid++]=temp;
        }
    }
    return;
}