#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 10007
typedef struct Node {
    int index;
    int val;
    struct Node* next;
} Node;
Node* buckets[SIZE];
int hashF(int val) { 
    int idx = val % SIZE;
    return (idx < 0) ? idx + SIZE : idx; 
}
void init() {
    for (int i = 0; i < SIZE; i++)
        buckets[i] = NULL;
}
Node* cN(int val, int index) {
    Node* res = (Node*)malloc(sizeof(Node));
    res->next = NULL;
    res->index = index;
    res->val = val;
    return res;
}
void AddNode(int val, int index) {
    int idx=hashF(val);
    Node *new=cN(val,index);
    new->next=buckets[idx];
    buckets[idx]=new;
}
int reverse(int val) {
    if (val == 0)
        return 0;
    int a = 0;
    while (val) {
        a = a * 10 + val % 10;
        val /= 10;
    }
    return a;
}
void updateMinDist(int val, int index, int* min) {
    int idx = hashF(val);
    Node* curr = buckets[idx];
    while (curr != NULL) {
        if (curr->val == val) {
            int dist = index - curr->index;
            if (dist < *min) *min = dist;
        }
        curr = curr->next;
    }
}
void freeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        Node* curr = buckets[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
}
int minMirrorPairDistance(int* a, int n) {
    init();
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        updateMinDist(a[i], i, &min);
        AddNode(reverse(a[i]), i);
    }
    freeHashTable();
    return (min == INT_MAX) ? -1 : min;
}