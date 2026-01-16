// Hash set - value is stored in the node
// This is faster because we do not traverse a whole array to find an elem.
// we create an array of nodes each correspoding to each different key produced by the hash function that is recquired.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
typedef struct Node{
    char *name;
    struct Node *next;
}Node;
Node *buckets[SIZE];
int hashFunction(const char *name){
    int sum=0;
    for(int i=0;i<strlen(name);i++) sum+=name[i];
    return sum%SIZE;
}
void __init__(){
    for(int i=0;i<SIZE;i++) buckets[i]=NULL;
}
Node *createNode(char *name){
    Node *new = (Node *)malloc(sizeof(Node));
    new->name=(char *)malloc(sizeof(name)+1);
    strcpy(new->name, name);
    new->name[sizeof(name)]='\0';
    new->next=NULL;
    return new;
}
void AddNode(char *name){
    int idx=hashFunction(name);
    if(buckets[idx]==NULL){
        buckets[idx]=createNode(name);
        return;
    }
    Node *curr = buckets[idx];
    while(curr->next!=NULL) curr=curr->next;
    curr->next = createNode(name);
    return;
}
int searchNode(char *name){
    int idx=hashFunction(name);
    Node *curr = buckets[idx];
    while(curr!=NULL){
        if(strcmp(name, curr->name)==0) return 1;
        curr=curr->next;
    }
    return 0;
}
void removeNode(char *name){
    // if(searchNode(name)==0){printf("Node not found\n");return;}
    int idx=hashFunction(name);
    Node *curr=buckets[idx];
    while(curr!=NULL && strcmp(name, curr->name)!=0){
        curr=curr->next;
    }
    if(curr==NULL){printf("Node not found\n");return;}
    Node *temp=curr->next;
    curr->next=curr->next->next;
    printf("Node with name = %s\n", temp->name);
    free(temp);
    return;
}
void printLinkedList(Node *start){
    Node *curr=start;
    while(curr!=NULL){
        printf("%s -> ", curr->name);
        curr=curr->next;
    }
    printf("null\n");
}
void printHashSet(){
    for(int i=0;i<SIZE; i++){
        printf("%d : ",i);
        printLinkedList(buckets[i]);
    }
    printf("\n");
    return;
}
int main(){
    __init__();
    AddNode("Divyansh");
    AddNode("Mihir");
    AddNode("Rohan");
    AddNode("Mummy");
    AddNode("Papa");
    AddNode("Urja Bhabhi");
    AddNode("Rishabh");
    AddNode("Rishika");
    AddNode("Jaiminie");
    printHashSet();
    removeNode("Rishabh");
    printHashSet();
    return 0;
}