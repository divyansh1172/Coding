#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int *a = malloc(2*n*sizeof(int));
        for(int i=0;i<2*n;i++) scanf("%d", a+i);
		
    }
    return 0;
}