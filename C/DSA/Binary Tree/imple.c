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

void inorderTraversal(Node *root){
    if(root==NULL)return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
    return;
}

void preOrderTraversal(Node *root){
    if(root==NULL)return;

    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return ;
}

void postOrderTraversal(Node *root){
    if(root==NULL)return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
    return;
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

    inorderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    return 0;
}