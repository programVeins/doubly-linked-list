#ifndef DLIST_H
#define DLIST_H

typedef int genericType; //Generic Datatype -> Can be changed later

typedef struct node node;

struct node
{
    genericType data;
    node* next;
    node* prev;
};

node* create(genericType toBoNoded);
genericType displayNode(node* toBeDisplayed);
node* deleteNode(node* head, node* toBeDeleted);
node* insertBeginning(node* head, genericType toBeInserted);
int insertEnding(node* head, genericType toBeInserted);
int insertAfter(node* head, genericType toBeInserted, genericType afterNodeWithData);
node* insertBefore(node* head, genericType toBeInserted, genericType beforeNodeWithData);
node* searchNode(node* head, genericType toBeSearched);

#endif