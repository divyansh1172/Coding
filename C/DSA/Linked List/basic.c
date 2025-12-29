// Linked List : This is a basic implementation of a linked list.
// A node is a struct with some data and a pointer pointing to the next node.
// This collection of nodes is knwown as the Linked List.


#include<stdio.h>
#include<stdlib.h>
typedef struct Node{     // The node that we declare 
    int val;             // The data that we store in a node 
    struct Node* next;   // Pointer to the next node 
}Node;

int main()
{
    // Node n1,n2,n3,n4;
    Node *n1= malloc(sizeof(Node));             // allocation of memery for the node in this in heap because malloc is used 
    Node *n2= (Node *)malloc(sizeof(Node));     
    Node *n3= (Node *)malloc(sizeof(Node));
    Node *n4= (Node *)malloc(sizeof(Node));
    n1->val=4;                                  // Assiging the values or data to be stores in this 
    n2->val=3;
    n3->val=1;
    n4->val=5;
    n1->next=n2;                                // connecting all the nodes
    n2->next=n3;
    n3->next= n4;
    n4->next=NULL;
    Node *current= n1;                          // Simple traveral of a linked list using another pointer node 
                                                // that points to the current node that we are on.
    while(current){
        printf("%d -> ", current->val);         // Printing the value.
        current=current->next;
    }
    printf("null\n");
    return 0;
}