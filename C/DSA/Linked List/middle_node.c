// Finding the mmid

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
} Node;
Node *createNode(int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}
void Print_LL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("null\n");
    return;
}
Node *middle_node(Node *head){
    if(head==NULL)return NULL;
    Node *slow, *fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *add_Node(Node *head, int val, int pos)
{
    if (pos <= 0) {
        printf("Invalid position\n");
        return head;
    }
    Node *newNode = createNode(val);
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    int i = 1;
    while (curr != NULL && i < pos - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        printf("Position not found\n");
        free(newNode);
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
int main()
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(1);
    Node *n3 = createNode(8);
    Node *n4 = createNode(90);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n1=add_Node(n1, 55, 3);
    Print_LL(n1);
    printf("%d\n", middle_node(n1)->val);
    return 0;
}