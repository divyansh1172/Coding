// Basic Implementation of a Queue using an array
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int *q;
    int front; 
    int rear;
    int capacity;
}Queue;
Queue *createQueue(int capa){
    Queue *res = malloc(sizeof(Queue));
    res->q = malloc(capa*sizeof(int));
    res->front=res->rear=-1;
    res->capacity=capa;
    return res;
}
int isEmpty(Queue *Q){
    return Q->front==-1;
}
int isFull(Queue *q){
    return q->rear == q->capacity-1;
}
void enQueue(Queue *Q,int x){
    if(isFull(Q)){printf("Queue Full\n");return;}
    if(isEmpty(Q)) Q->front=0;
    Q->q[++Q->rear]=x;
}
int deQueue(Queue *Q){
    if(isEmpty(Q)){printf("Queue empty\n"); return -1;}
    int val=Q->q[Q->front++];
    if(Q->front > Q->rear){
        Q->front=Q->rear=-1;
    }
    return val;
}
int peek(Queue *Q){
    if(isEmpty(Q)){printf("Queue empty\n"); return -1;}
    return Q->q[Q->front];
}
void display(Queue *Q){
    if(isEmpty(Q)){printf("Queue empty\n"); return;}
    for(int i= Q->front ; i<= Q->rear; i++) printf("%d ",Q->q[i]);
}
void freeQueue(Queue *Q){
    free(Q->q);
    free(Q);
    return;
}
int main()
{
    Queue *q = createQueue(5);

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", deQueue(q));
    printf("Front: %d\n", peek(q));

    display(q);

    freeQueue(q);
    return 0;
}