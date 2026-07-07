#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int val;
}Node;

Node *createNode(int val){
    Node *new= malloc(sizeof(Node));
    new->left=NULL;
    new->right=NULL;
    new->val=val;
    return new;
}
int max(int a, int b){
    return (a>b)? a:b;
}
int min(int a, int b){
    return (a>b)? b:a;
}
int MaximumNodeVal(Node *root){
    if(root==NULL) return INT_MIN;
    return max(root->val, max(MaximumNodeVal(root->left), MaximumNodeVal(root->right)));
}
int MinimumNodeVal(Node *root){
    if(root==NULL) return INT_MAX;
    return min(root->val, min(MinimumNodeVal(root->left), MinimumNodeVal(root->right)));
}
int EvenNodes(Node *root){
    if(root==NULL)return 0;
    int leftEven= EvenNodes(root->left);
    int rightEven = EvenNodes(root->right);
    if(root->val %2==0) return 1+leftEven+rightEven;
    else return leftEven+rightEven;
}
int main(){
    Node *root=createNode(10);
    Node *a=createNode(5);
    Node *b=createNode(20);
    Node *c=createNode(2);
    Node *d=createNode(7);
    Node *e=createNode(30);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;

    return 0;
}