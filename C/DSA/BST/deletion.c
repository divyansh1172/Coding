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

Node *findMin(Node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

Node *deleteNode(Node *root, int key){
    if(root==NULL) return NULL;
    if(key > root->val) root->right=deleteNode(root->right, key);
    else if (key < root->val) root->left= deleteNode(root->left, key);
    else{
        if(root->left==NULL && root->right== NULL){
            free(root);return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else{
            Node *min = findMin(root->right);
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
        }
    }
    return root;
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

    // printf("%d \n", isNodePresent(root, 10));
    return 0;
}