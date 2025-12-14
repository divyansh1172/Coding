// Insertion Sort
// we shift the first elem in the unsorted array to its postion in the sorted array.
// the outer loop runs n-1 times.
// Time Complexity:
// Best case: O(n) already sorted
// Worst Case: O(n^2) descending
// Average case : O(n^2)
#include<stdio.h>

void InsertionSort(int a[], int n){
    for(int i=1; i< n; i++){
        int j= i-1;                 // position from where to check from behind
        int key = a[i];             // the elem to be inserted 
        while(j>=0 && a[j]>=key){   // checking the position to insert 
            a[j+1]=a[j];            // shifting elements
            j--;
        }
        a[j+1]=key;                 // Inserting the elem at the correct position 
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
    InsertionSort(a,5);
    print(a,5);
    return 0;
}