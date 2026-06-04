#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int addMinimum(char* s) {
    int n=strlen(s);
    if(n==1) return 2;
    else if (n==2){
        if(s[0]<s[1]) return 1;
        else return 4;
    }
    char stack[4];
    int top=0, cost=0;
    for(int i=0;i<n;i++){
        if(top==0){
            stack[top++]=s[i];
        }
        else{
            if(s[i]==stack[top-1]){
                if(top==1){
                    cost+=2;
                    top=0;
                    stack[top++]=s[i];
                }
                else{
                    top=0;
                    cost+=1;
                    stack[top++]=s[i];
                }
            }
            else if(s[i]>stack[top-1]){
                if(s[i]-stack[top-1]==1){
                    if(top==1)stack[top++]=s[i];
                    else top=0;
                }
                else{
                    top=0;
                    cost+=1;
                }
            }
            else{
                if(top==1){
                    cost+=2;
                    top=0;
                    stack[top++]=s[i];
                }
                else{
                    cost+=1;
                    top=0;
                    stack[top++]=s[i];
                }
            }
        }
        
    }
    // free(stack);
    if(top!=0){
        if(top==1)
            cost+=2;
        else if(top==2)
            cost+=1;
    }
    return cost;
    
}

int main(){
    printf("%d\n", addMinimum("aaa"));
    printf("%d\n", addMinimum("b"));
    printf("%d\n", addMinimum("abc"));
    printf("%d\n", addMinimum("aaaaba"));
    printf("%d\n", addMinimum("aaaabb"));
    return 0;
}
