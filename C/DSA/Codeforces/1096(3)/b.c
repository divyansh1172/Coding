#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int k;
        scanf("%d", &k);
        char *s=malloc(k+1);
        scanf("%s", s);
        int open=0, close=0;
        for(int i=0;i<k;i++){
            if(s[i]==')') close++;
            else open++;
        }
        if(close!=open) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}