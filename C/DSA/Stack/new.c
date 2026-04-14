#include<stdio.h>
void push(int *a, int n, int val, int *k){
    if(*k==n-1) return;
    (*k)++;
    a[*k]=val;
    return;
}
int pop(int *a, int n, int *k){
    if(*k==-1) return -1;
    int val=a[(*k)--];
    return val;
}
int peep(int *a, int n, int k){
    if (k==-1) return -1;
    return a[k];
}
void print(int a[], int n){
    for(int i=0;i<=n; i++) printf("%d ", a[i]);
    printf("\n");
    return ;
}
int main()
{
    int capa=10;
    int k=-1;
    int stack[capa];
    push(stack, capa, 10, &k);
    push(stack, capa, 20, &k);
    push(stack, capa, 30, &k);
    print(stack, k);
    pop(stack, capa, &k);
    print(stack, k);
    return 0;
}