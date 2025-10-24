#include <stdio.h>
#define MAX 10

int a[MAX];
int front = -1, rear = -1;

int isFull()
{
    return ((front==0 && rear==MAX-1) || front==rear+1);
}

int isEmpty()
{
    return (front ==-1);
}

void insertFront(int x)
{
    if(isFull)
    {
        printf("The deque is full\n");return;
    }
    if(front ==-1)
    {
        front=rear=0;
    }
    else if(front ==0)
    {
        front = MAX-1;
    }
    else
    {
        front --;
    }
    
    a[front]=x;
}

