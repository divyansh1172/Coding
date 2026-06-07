#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// keep multiples of 6 at left with even nums, multiples of 3 at other end and neutral at middle so we 
// count all and add them in the ans array 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int *a=malloc(n*sizeof(int));
        int mul_6=0, even=0, mul_3=0, odd=0;
        for(int i=0;i<n;i++) {
            scanf("%d", a+i);
            if(a[i]%6==0) mul_6++;
            else if(a[i]%2==0) even++;
            else if(a[i]%3==0) mul_3++;
            else odd++;
        }
        // mult 6 from 0 to mul_6-1 order doesnt matter
        // mult of 3 upto n-1 to n - mul_3
        // even UPTO m6 + even-1 from m6
        // ans array:
        int *ans= malloc(n*sizeof(int));
        even+=mul_6;
        odd+=even;
        mul_3+=odd;
        for(int i=0;i<n;i++){
            if(a[i]%6==0){
                ans[mul_6-- -1]=a[i];
            }
            else if(a[i]%2==0) {
                ans[even-- -1]=a[i];
            }
            else if(a[i]%3==0) {
                ans[mul_3-- -1]=a[i];
            }
            else {
                ans[odd-- -1]=a[i];
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        free(ans);
        free(a);
    }
    return 0;
}