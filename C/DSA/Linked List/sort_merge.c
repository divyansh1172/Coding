#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
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
Node *middle_node(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow, *fast;
    slow  = head;
    fast=head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *first, Node *second){
    if(first==NULL) return second;
    if(second==NULL) return first;
    Node *res = NULL;
    if(first->val <= second->val){
        res=first;
        res->next=merge(first->next, second);
    }
    else{
        res=second;
        res->next=merge(first, second->next);
    }
    return res;
}
Node *merge_sort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=middle_node(head);
    Node *right=mid->next;
    mid->next=NULL;
    Node *left=head;

    left=merge_sort(left);
    right=merge_sort(right);
    return merge(left,right);
}
int main()
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(1);
    Node *n3 = createNode(8);
    Node *n4 = createNode(90);
    Node *n5 = createNode(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Print_LL(n1);
    n1 = merge_sort(n1);
    Print_LL(n1);
    return 0;
}