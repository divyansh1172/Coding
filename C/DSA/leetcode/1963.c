#include<string.h>
#include<stdio.h>


// typedef struct Node{
//     char s;
//     int index;
// }Node;
// int minSwaps(char* s) {
//     int n=strlen(s);
//     Node stack[n];
//     for(int i=0;i<n;i++){

//     }
// }

int minSwaps(char* s){
    int n=strlen(s);
    int swap=0, open=0,close=0;
    for (int i = 0; i < n; i++){
        if(s[i]==']') close++;
        else open++;
        if(close>open){
            swap++;
            close--;
            open++;
        }
    }
    return swap;
}

int main(){
    printf("%d\n", minSwaps("][]["));
    printf("%d\n", minSwaps("]]][[["));
    printf("%d\n", minSwaps("[]"));
    return 0;
}
