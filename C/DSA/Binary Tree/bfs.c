#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node{
    struct Node *left, *right;
    int val;
}Node;

Node *queue[MAX];
int front=0, rear=-1;

Node *createNode(int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->left=newNode->right=NULL;
    newNode->val=val;
    return newNode;
}

void enqueue(Node *node){
    queue[++rear]=node;
}

Node *dequeue(){
    return queue[front++];
}
int isQueueEmpty(){
    return front > rear;
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

    enqueue(root);
    while(!isQueueEmpty()){
        Node *curr=dequeue();
        if(curr->left!=NULL)
            enqueue(curr->left);
        if(curr->right!=NULL)
            enqueue(curr->right);
        printf("%d ", curr->val);
    }
    return 0;
}