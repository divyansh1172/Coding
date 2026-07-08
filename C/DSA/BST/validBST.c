#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    struct Node *left, *right;
    int val;
}Node;

Node *createNode(int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->left=newNode->right=NULL;
    newNode->val=val;
    return newNode;
}

int isValidBST(Node *root, int max, int min){
    if(root==NULL) return 1;
    if(root->val >= max || root->val <= min) return 0;
    return isValidBST(root->left, root->val, min) && isValidBST(root->right, max, root->val);
}

int main(){
    Node *root= createNode(15);
    Node *a= createNode(8);
    Node *c= createNode(4);
    Node *d= createNode(10);
    Node *b= createNode(25);
    Node *e= createNode(20);
    Node *f= createNode(30);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;

    printf("%d \n", isValidBST(root, INT_MAX, INT_MIN));
    return 0;
}