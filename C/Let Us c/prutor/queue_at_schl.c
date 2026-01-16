#include<stdio.h>
void swapp(char *a, char *b){
    char temp=*a;*a=*b;*b=temp;
    return;
}
int main(){
    int n,t;
    scanf("%d %d", &n, &t);
    char a[n+1];
    scanf("%s", a);
    for(int time = 0; time<t; time++){
        for(int i=0;i<n-1; i++){
            if(a[i]=='B'&&a[i+1]=='G') {swapp(&a[i], &a[i+1]);i++;}
        }
    }
    printf("%s", a);
    return 0;
}