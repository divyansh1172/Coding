#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int val;
}Node;

int max(int a, int b){
    return (a>b)? a:b;
}

Node *createNode(int val){
    Node *new= malloc(sizeof(Node));
    new->left=NULL;
    new->right=NULL;
    new->val=val;
    return new;
}

int countNodes(Node *root){
    if(root==NULL) return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int leafNodes(Node *root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    else return leafNodes(root->left)+leafNodes(root->right);
}

int heightOfBinaryTree(Node *root){
    if(root==NULL)return -1;
    return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}

int countInternalNodes(Node *root){
    if(root==NULL)return 0;
    if(root->left!=NULL || root->right!=NULL) return 1+countInternalNodes(root->left)+ countInternalNodes(root->right);
    else return 0;
}

int EvenNodes(Node *root){
    if(root==NULL)return 0;
    int leftEven= EvenNodes(root->left);
    int rightEven = EvenNodes(root->right);
    if(root->val %2==0) return 1+leftEven+rightEven;
    else return leftEven+rightEven;
}

int OddNodes(Node *root){
    return countNodes(root) - EvenNodes(root);
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

    // inorderTraversal(root);
    // printf("\n");
    // preOrderTraversal(root);
    // printf("\n");
    // postOrderTraversal(root);
    printf("%d\n",heightOfBinaryTree(root));

    return 0;
}