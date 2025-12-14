// Counting Sort:
// Only for non-negative numbers
// We find the max of the array and then
// We find the frequency of each number upto max and then reconstruct the array using the frequnecy array
// Time Complexity: O(N +k) where k is the number of different values the in the array
// best case: O(N)...

#include<stdio.h>
#include<stdlib.h>
void CountingSort(int a[], int n){
    int max=0;
    for(int i=0;i<n;i++){                          // finding the maximum elem in the array 
        if(max<a[i]) max=a[i];
    }
    int *freq = (int *)calloc(max+1, sizeof(int));
    for(int i=0; i<n;i++){
        freq[a[i]]++;                              // Building the frequency array
    }
    int i=0;
    for(int j=0; j<=max+1; j++){                   // Reconstructing the sorted array using frequency array
        while(freq[j]--){
            a[i++]=j;
        }
    }
    free(freq);
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
    CountingSort(a,5);
    print(a,5);
    return 0;
}