// Stack - DS that can store many elems
// Like a plate of pancakes we can only operate on first elems
// Five basic operations:
// 1. push- add a new elem to top
// 2. peek- get the first elem
// 3. pop-delete the first elem and print it
// 4. size of stack
// 5. isEmpty
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *stack;
    int capacity;
    int top;
} Stack;

Stack *createStack(int capa)
{
    Stack *new = (Stack *)malloc(sizeof(Stack));
    new->stack = (int *)malloc(capa * sizeof(int));
    new->capacity = capa;
    new->top = -1;
    return new;
}
void push(Stack *s, int val)
{
    if (s->top == s->capacity - 1)
    {
        printf("Stack is full \n");
        return;
    }
    s->stack[++(s->top)] = val;
    return;
}
int peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Empty!!!\n");
        return -1;
    }
    return s->stack[s->top];
}
int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Empty!!!\n");
        return -1;
    }
    return s->stack[s->top--];
}
int isEmpty(Stack *s) { return s->top == -1; }
int StackSize(Stack *s) { return s->top + 1; }
void freeStack(Stack *s)
{
    free(s->stack);
    free(s);
}
int main()
{
    Stack *s = createStack(10);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));
    printf("Size: %d\n", StackSize(s));

    freeStack(s);
    return 0;
}
