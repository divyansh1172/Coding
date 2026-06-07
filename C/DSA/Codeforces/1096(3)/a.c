#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a,b;
        scanf("%d %d", &a, &b);
        if((a&1)==1 && (b&1)==1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}