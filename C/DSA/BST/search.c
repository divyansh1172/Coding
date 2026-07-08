#include<stdio.h>
#include<stdlib.h>

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

int isNodePresent(Node *root, int key){
    if(root == NULL) return 0;
    if(key> root->val)
        return isNodePresent(root->right, key);
    else if(key < root->val)
        return isNodePresent(root->left, key);
    else
        return 1;
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

    printf("%d \n", isNodePresent(root, 10));
    return 0;
}