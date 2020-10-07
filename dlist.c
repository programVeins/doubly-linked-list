#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#define MAKENODE (node*) malloc (sizeof(node));

node* create(genericType toBoNoded)
{
    node* thisNode = MAKENODE;
    thisNode->data = toBoNoded;
    thisNode->next = NULL;
    thisNode->prev = NULL;
    return thisNode;
}

genericType displayNode(node* toBeDisplayed)
{
    genericType dataPointer = toBeDisplayed->data;
    return dataPointer;
}

node* insertBeginning(node* head, genericType toBeInserted)
{
    node* startNode = create(toBeInserted);
    startNode->next = head;
    startNode->prev = NULL;
    head->prev = startNode;
    head = startNode;

    return head;
}

int insertEnding(node* head, genericType toBeInserted)
{
    node* endNode = create(toBeInserted);
    node* slider = head; //Creates a slider that points to head
    endNode->next = NULL;

    while(slider->next != NULL)
    {
        slider = slider->next; //Traversal, moves the slider across the list till it's 'next' points to NULL
    }
    slider->next = endNode; //Assigns endNode as the final node
    endNode->prev = slider; //Back-link
    

    return slider == NULL ? -1 : 0; //Conditional return, returns -1 (Fail) if slider is NULL else returns 0 (Success)
}

int insertAfter(node* head, genericType toBeInserted, genericType afterNodeWithData)
{
    node* tempNode = create(toBeInserted);
    node* slider = head;

    while((slider->data != afterNodeWithData) && (slider->next != NULL))
    {
        slider = slider->next; //Traversal
    }
    if(slider->data != afterNodeWithData)
    {
        return -1;
    }
    if(slider->next != NULL)
    {
        tempNode->next = slider->next;
        slider->next->prev = tempNode; //Back-link
        
    }
    slider->next = tempNode;
    tempNode->prev = slider; //Back-link

    return slider == NULL ? -1 : 0; //Conditional return

}

node* insertBefore(node* head, genericType toBeInserted, genericType beforeNodeWithData)
{
    node* tempNode = create(toBeInserted);
    node* slider = head;

    if(slider->data == beforeNodeWithData) //Similar to insertBeginning
    {
        slider->prev = tempNode;
        tempNode->next = slider;
        head = tempNode; //Shifts head
        puts("\nData successfully inserted!\n");
        return head;
    }
    while((slider->data != beforeNodeWithData) && (slider->next != NULL))
    {
        slider = slider->next; //Traversal
    }
    if(slider->data != beforeNodeWithData)
    {
        puts("\nEnter a known data element!\n");
        return head;
    }
    tempNode->prev = slider->prev; //Back-link
    slider->prev->next = tempNode;
    slider->prev = tempNode; //Back-link
    tempNode->next = slider;
    
    puts("\nData successfully inserted!\n");
    return head; //Returns head

}

node* deleteNode(node* head, node* toBeDeleted)
{
    if((toBeDeleted->next == NULL) && (toBeDeleted->prev == NULL)) //Case of only head
    {
        free(toBeDeleted);
        return NULL;
    }
    if(toBeDeleted == head)
    {
        toBeDeleted->next->prev = NULL; //Remove back-link of second node
        head = toBeDeleted->next; //Move head by one place
        free(toBeDeleted); //De-allocates memory space of head
        return head;
    }

    if(toBeDeleted->next != NULL) //Every intermediate node
    {
        toBeDeleted->next->prev = toBeDeleted->prev; //Modifies Back-link
        toBeDeleted->prev->next = toBeDeleted->next; //Modifies Front-link
    }
    else //End node
    {
        toBeDeleted->prev->next = NULL; //Removes front-link of last-but-one node
    }

    free(toBeDeleted); //De-allocates memory space of node
    return head;
}

node* searchNode(node* head, genericType toBeSearched)
{
    node* slider = head;

    while(slider->next != NULL)
    {
        if(slider->data == toBeSearched)
        {
            return slider;
        }
        slider = slider->next;
    }
    if(slider->data == toBeSearched)
    {
        return slider;
    }
    return NULL;
}