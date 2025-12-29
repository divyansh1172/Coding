// implementation of a stack using linked list
// same functions but some changes while using push and pop
// while pushing we need to create a new node and while popping we will need to free it
// the top elem is head of the ll
// we maintain a counter size for the size of stack
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;
typedef struct Stack
{
    Node *head;
    int size;
} Stack;
Stack *createStack()
{
    Stack *new = malloc(sizeof(Stack));
    new->head = NULL;
    new->size = 0;
    return new;
}
void push(Stack *s, int val)
{
    Node *new = malloc(sizeof(Node));
    new->val = val;
    new->next = s->head;
    s->head = new;
    s->size++;
}
int popStack(Stack *s)
{
    if (s->size == 0)
    {
        printf("Empty Stack!!!\n");
        return -1;
    }
    Node *popy = s->head;
    s->head = s->head->next;
    int pop_val = popy->val;
    free(popy);
    s->size--;
    return pop_val;
}
int peek(Stack *s)
{
    if (s->size == 0)
    {
        printf("Empty Stack!!!\n");
        return -1;
    }
    return s->head->val;
}
int isEmpty(Stack *s)
{
    return s->size == 0;
}
int Size(Stack *s)
{
    return s->size;
}
void DisplayStack(Stack *s){
    Node *cur=s->head;
    while(cur!=NULL){
        printf("%d->", cur->val);cur=cur->next;
    }
    printf("null\n");
}
void freeStack(Stack *s)
{
    while (!isEmpty(s))
        popStack(s);
    free(s);
}
