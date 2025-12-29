// Using insertion sort to sort a given Linked list.
// What we do is create a sorted linked list and we add elems from original Linked List one by one
// Time Complexity - O(N^2); Space Complexity - O(1)
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node* Insertion_sort(Node *head){ // returning the new head 
    Node *current = head;         // the pointer to the elem to be inserted
    Node *sorted = NULL;          // the node of sorted Linked List
    while(current != NULL ){
        Node *new= current->next; // remembering the next node 
        if(sorted == NULL || current->val < sorted->val){ // if the linked list is empty or the elem to be inserted is smallest 
            current->next = sorted;                       // connect it to the sorted LL and make it the new head
            sorted=current;
        }
        else{ // else find the position to be added
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->val < current->val)
            {
                temp = temp->next;
            }
            // temp is the last node that is smaller than current->val so the current node is to be inserted after temp
            current->next=temp->next;
            temp->next=current;
        }
        current = new; // setting the current to next node
    }
    return sorted; // returning the new head 
}

int main()
{
    Node *n1= malloc(sizeof(Node));             
    Node *n2= (Node *)malloc(sizeof(Node));     
    Node *n3= (Node *)malloc(sizeof(Node));
    Node *n4= (Node *)malloc(sizeof(Node));
    n1->val=4;                                 
    n2->val=3;
    n3->val=1;
    n4->val=5;
    n1->next=n2;                                
    n2->next=n3;
    n3->next= n4;
    n4->next=NULL;
    Node *current= Insertion_sort(n1);                          
    while(current){
        printf("%d -> ", current->val);       
        current=current->next;
    }
    printf("null\n");
}