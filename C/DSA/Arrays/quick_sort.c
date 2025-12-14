// Quick Sort:
// Divide and conquer strategy using recursion --- Not Stable Sort.
// We choose a pivot and put all the elems smaller than the pivot to its left and the larger to right.
// in this way the position of the pivot is fixed and the correct.
// the function partition does this and returns the position of the pivot 
// position of pivot is correct then we recursively solve the smaller arrays from start to pivot_index-1 and pI+1 to end..
// Time Complexity: Best case O(N) Worst Case : O(N^2) Average: O(N log N)


#include<stdio.h>
// This function rearranges the array such that all the elems less that pivot are of left of pivot and larger
// are on right and returns the index of the pivot 
int partition(int a[], int low, int high){
    int pivot=a[high];              // choosing the pivot to be the last elem of the array 
    int i=low-1;                    // for keeping track of the position of pivot 
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
    return i+1; // returning the position of pivot this is the correct position for the elem in finally sorted array
}
// Recursive function to divide the array into smaller parts and 
void quickSort(int a[], int low, int high){
    if(low<high){
        int pI = partition(a,low,high);
        quickSort(a, low, pI-1);         // calling this function for sub-array from low to pI-1 and from pI+1 
        quickSort(a, pI + 1, high);      // to high because the postion of pI is correct only now
    }
    return;
}
void print(int a[], int n){
    for(int i=0;i<n; i++) printf("%d ", a[i]);
    printf("\n");
    return ;
}
int main(){
    int a[5]={3,2,4,5,1};
    print(a,5);
    quickSort(a,0,4);
    print(a,5);
    return 0;
}