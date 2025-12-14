// Insertion Sort:
// finding the smallest elem in the unsorted part and placing it at the starting of the unsorted part
// outer loop runs n-1 times indicating where the smallest elem will be placed 
// inner loop finds the position to put the elem
// Time complexity: O(N^2)
#include<stdio.h>

void SelectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){ // i denotes the position of new min elem to be added
        int min = a[i];
        int min_index=i;
        for(int j=i+1; j<n; j++) {
            if(min>a[j]) {
                min_index=j;
            }
        }
        int temp = a[min_index];
        a[min_index] = a[i];
        a[i]=temp;
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
    SelectionSort(a,5);
    print(a,5);
    return 0;
}