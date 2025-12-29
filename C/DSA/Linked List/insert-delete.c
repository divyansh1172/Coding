#include <stdio.h>
#include <stdlib.h>
typedef struct Node // making a structure for the node
{
    int val;
    struct Node *next;
} Node;

Node *createNode(int val) // allocating memory in heap for node and assiging val
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}
void Print_LL(Node *head) // printing the Linked list 
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
Node *delete(Node *head, int val) // deleting the first node such that node->val=val and returning the new head 
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->val == val) // if its head 
    {
        Node *temp = head->next;
        free(head);
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->val != val) // finding node such that the next node is to be deleted 
    {
        curr = curr->next;
    }
    if (curr->next == NULL) // the value not found
    {
        printf("Value %d not found\n", val);
        return head;
    }
    Node *del = curr->next; // deleting the node
    curr->next = del->next;
    free(del);

    return head;
}
Node *add_Node(Node *head, int val, int pos) // inserting the node at the given position and returning the new head 
{
    if (pos <= 0) { // invalid pos
        printf("Invalid position\n");
        return head;
    }
    Node *newNode = createNode(val);
    if (pos == 1) { // new node at head 
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    int i = 1;
    while (curr != NULL && i < pos - 1) { // finding the node after which we have to insert the new node 
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        printf("Position not found\n");
        free(newNode);
        return head;
    }
    newNode->next = curr->next; // inserting the node
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
    Print_LL(n1);
    printf("Deleting node n3\n");
    n1 = delete(n1, n3->val);
    Print_LL(n1);
    printf("Adding a new node with val = 55 at posoition 3\n");
    n1=add_Node(n1, 55, 3);
    Print_LL(n1);
    return 0;
}