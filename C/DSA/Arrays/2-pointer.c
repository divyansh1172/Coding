// Two pointer method - using 2 pointers to find an elem in a sorted array like binary search
#include<stdio.h>

int contains(int a[], int n,  int target){
    int start = 0;
    int end = n-1;
    while(start < end){
        int mid=(end+start)/2;
        if(a[mid] == target) return 1;
        else if(a[mid] > target) end=mid-1;
        else if (a[mid]<target) start=mid+1;
    }
    return 0;
}