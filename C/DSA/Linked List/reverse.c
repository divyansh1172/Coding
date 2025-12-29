#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    return node;
}

void print(Node* head) {
    Node* curr = head;
    while(curr) {
        printf("%d->", curr->val);
        curr=curr->next;
    }
    printf("null\n");
    return ;
}
Node* reverse(Node* head) {
    Node* curr = head;
    Node* nxt = head;
    Node* prev = NULL;
    while(nxt) {
        nxt = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main() {
    Node* node1 = createNode(6);
    Node* node2 = createNode(5);
    Node* node3 = createNode(4);
    Node* node4 = createNode(-2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("LL before reversal: ");
    print(node1);
    printf("LL after reversal: ");
    print(reverse(node1));

    return 0;
}