// Binary Search: Time Complexity: O(logN)
// Useful for sorted arrays
// Checking the middle elem if the target is greater than the mid elem then
// move to right otherwise left and again check the mid elem till we get the recq elem
#include<stdio.h>
int partition(int a[], int low, int high){
    int pivot=a[high]; // choosing the pivot to be the last elem of the array 
    int i=low-1; 
    for(int j=low; j<high; j++){
        if(a[j] <= pivot){
            i++;
            int temp = a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1] = a[high];
    a[high]=temp;
    return i+1;
}
void quickSort(int a[], int low, int high){
    if(low<high){
        int pI = partition(a,low,high);
        quickSort(a, low, pI-1);
        quickSort(a, pI + 1, high);
    }
    return;
}
int BinarySeach(int a[], int n, int target){
    int left=0, right=n-1; 
    while(left<=right){
        int mid = (left+right)/2;
        if(a[mid]==target) return mid;// if a[mid] == target we found the elem then return mid
        else if(a[mid]< target) // if a[mid]<target then we are checking towards the left, so we move it to right
            left=mid + 1;
        else right=mid-1; // else we move towards left
    }
    return -1;// if the target is not found
}