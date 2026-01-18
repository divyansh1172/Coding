#include<stdio.h>

void printSpiralMatrix(int m, int n, int a[m][n]){
    int top=0, left=0, right=n-1, bottom=m-1;
    int count=0;
    while(top<=bottom && left <= right){
        if(count%4==0){
            for(int i=left; i<=right; i++) printf("%d ", a[top][i]);
            top++;
        }
        else if(count%4==1){
            for(int i=top; i<=bottom; i++) printf("%d ", a[i][right]);
            right--;
        }
        else if(count%4==2){
            for(int i=right; i>=left; i--) printf("%d ", a[bottom][i]);
            bottom--;
        }
        else{
            for(int i=bottom; i>=top; i--) printf("%d ", a[i][left]);
            left++;
        }
        if(top > bottom || left > right)
            break;
        count++;
    }
    return;
}