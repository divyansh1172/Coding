// Radix Sort:
// Sorting the arary based on the digits from the least significant digit.
// We store the numbers in a 2-D array with the first index indicating the digit ie from 0-9 
// We sort the 2D array row wise and put it back to the og array index wise from the sorted 2-D array
// Time Complexity : O(N*k) where is number of digits in highest value in array
#include<stdio.h>
void bubbleSort(int a[], int n){  // Simple bubbleSort function for sorting
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
void RadixSort(int a[], int n){
    int max=a[0];
    for(int i=1; i<n; i++) if(max < a[i]) max=a[i];   // finding max in array
    int exp=1;                                        // setting the exponent for getting each digit in a number 
    while(max/exp > 0){
        int radix_arr[10][n];                         // This array stores the elems of a[] according to the digits 0-9
        int count[10]={0};                            // This stores the number of elems in each row of radix 
        
        for(int i=0; i<n ;i++){
            int rI = (a[i]/exp)%10;                   // extracting that digit
            radix_arr[rI][count[rI]++]= a[i];         // filling the array and the count array 
        }
        for (int i = 0; i < 10; i++)
            bubbleSort(radix_arr[i], count[i]);       // sorting each row of radix array 
        
        int index=0;                                  // putting the array back together number by number from top to bottom
        for(int i=0; i<10; i++)
            for(int j=0;j<count[i]; j++)
                a[index++]= radix_arr[i][j];
        exp*=10;
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
    RadixSort(a,5);
    print(a,5);
    return 0;
}