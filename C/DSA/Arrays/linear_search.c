// Linear Search:
// Searching an elem from starting to ending 
// useful for all arrays
// Time Complexity: O(N) -> constant

#include<stdio.h>

int LinearSearch(int a[], int n, int target){
    for(int i=0;i<n;i++){
        if(a[i]==target)
            return i;
    }
    return -1;
}
int main()
{
    int a[]={10,20,50,60,70,80, 100, 67};
    int tar= LinearSearch(a ,8,60 );
    if(tar!=-1){printf("The elem %d is at %d index\n", 60,tar);}
    return 0;

}