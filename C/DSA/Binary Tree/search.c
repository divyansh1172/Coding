#include<stdio.h>
#include<stdlib.h>

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

int isNodePresent(Node *root, int key){
    if(root==NULL) return 0;
    if(root->val == key )return 1;
    return isNodePresent(root->left, key) || isNodePresent(root->right, key);
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
    printf("%d\n", isNodePresent(root, 7));
    return 0;
}