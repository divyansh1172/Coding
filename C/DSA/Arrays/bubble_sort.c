// the largest element gets bubbled to the end 
// we check for adjacent elems and if the condo is true we swap hem till we get the sorted array
// the outer loop runs for n-1 times and the inner loop runs for n-i-1 times

#include<stdio.h>

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int swapp=0;
        for(int j=0;j<n-i-1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapp=1;
            }
        }
        if(!swapp) return;
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
    bubbleSort(a,5);
    print(a,5);
    return 0;
}