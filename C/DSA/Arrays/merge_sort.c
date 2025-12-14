// Merge Sort:
// Best case , worst case and average Time Complexity: O(N logN)
// We need 2 functions one for recursively breaking the array till single elems and another to merge them back together
// merge them back together in a sorted way

#include<stdio.h>
// This function merges elems of the array which contains two sorted sub-arrays from left to mid and m+1 to right 
void merge(int a[], int left, int mid, int right){
    int n1 = mid - left +1;                         // number of elems in the 1st sorted sub-array
    int n2 = right-mid;                             // number of elems in the 2nd sorted sub-array

    int L[n1], R[n2];                              

    // Copying the elements into L and R
    for(int i=0; i<n1; i++) {L[i]= a[left+i];}  
    for(int j=0; j<n2; j++) R[j]= a[mid + j+1];

    // k is the index where we will insert the elem, i and j denote the index of the candidates that can be inserted in the fully sorted array
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){ // if left candidate is smaller it is inserted in the array otherwise the right candidate is inserted 
            a[k++]=L[i++];
        }
        else a[k++]=R[j++];
    }
    // whichever array is not used up is copied into the final array 
    while(i<n1) a[k++] = L[i++];
    while (j<n2) a[k++]=R[j++];
    return;
}
// This function breaks the arrays into equal sub-arrays till there are only single elems are there and then 
// we start merging them up. 
void MergeSort(int a[], int left, int right){
    if(left<right){
        int mid= (left + right)/2;      
        MergeSort(a, left, mid);        // breaking the array 
        MergeSort(a, mid+1, right);
        merge(a,left, mid, right);      // merging the array back
    }
}

void print(int a[], int n){
    for(int i=0;i<n; i++) printf("%d ", a[i]);
    printf("\n");
    return ;
}
int main(){
    int a[5]={3,2,4,5,1};
    print(a,5);
    MergeSort(a,0,4);
    print(a,5);
    return 0;
}