#include<stdio.h>
#include<string.h>

int longestValidParentheses(char* s) {
    int n=strlen(s);
    if(n==0) return 0;
    int stack[n], top=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') stack[top++]=i;
        else{
            if(top!=0){
                if(s[stack[top-1]]=='(') top--;
                else stack[top++]=i;
            }
            else stack[top++]=i;
        }
    }
    if(top==0) return n;
    int longest=0;
    for(int i=1;i<top;i++){
        // if(top>0 && top<n-1){
            if(stack[i]-stack[i-1]-1 > longest) longest=stack[i]-stack[i-1]-1;
        // }
    }
    // if(st)
    if(stack[0] >longest) longest=stack[0];
    if( n-1 - stack[top-1] > longest) longest= n-1 - stack[top-1];
    return longest;
}

int main(){
    printf("%d \n", longestValidParentheses("()(()"));
    printf("%d \n", longestValidParentheses("((("));
    printf("%d \n", longestValidParentheses(")))"));
    printf("%d \n", longestValidParentheses("()()()"));
    printf("%d \n", longestValidParentheses("(()()())()()))()()(((()))))"));
    printf("%d \n", longestValidParentheses(""));
    printf("%d \n", longestValidParentheses("()(()()"));
    printf("%d \n", longestValidParentheses("())()()((()()()))()()()()()()())))(()(())))()())()()()())(((()))))()()())()()()()())))("));
    return 0;
}