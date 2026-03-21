#include "../include/doubly_circular_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

Status insertAtHead(LinkedList *list,int data){
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return ERR_MALLOC_FAIL;
    }
    
    if (list->tail == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode; 
        list->tail = newNode;
    }else{
        Node *head = list->tail->next;
        newNode->next = head;
        newNode->prev = list->tail;
        head->prev = newNode;
        list->tail->next = newNode;
    }

    list->size++;
    return SUCCESS;
    
}

Status insertAtEnd(LinkedList *list,int data){
    if (list->tail == NULL)
    {
        return insertAtHead(list,data);
    }

    Node *newNode = createNode(data);
    if(newNode == NULL){
        return ERR_MALLOC_FAIL;
    }
    
    Node *head = list->tail->next;
    newNode->next = head;
    newNode->prev = list->tail;
    head->prev = newNode;
    list->tail->next = newNode;

    list->tail = newNode;

    list->size++;
    return SUCCESS;
}

Status insertAtPosition(LinkedList *list,int data,int pos){
    if (pos <= 0 || pos > list->size+1)
    {
        return ERR_INVALID_POS;
    }

    if (pos == 1)
    {
        return insertAtHead(list,data);
    }

    if (pos == list->size+1)
    {
        return insertAtEnd(list,data);
    }
    
    Node *temp = list->tail->next;
    for(int i = 1;i<pos-1;i++){
        temp = temp->next;
    }
    
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return ERR_MALLOC_FAIL;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    list->size++;
    return SUCCESS;
}

Status deleteFromHead(LinkedList *list){
    if (list == NULL || list->tail == NULL) {
        return ERR_EMPTY_LIST;
    }

    Node *nodeToDelete = list->tail->next; 

    if (list->tail == nodeToDelete) { 
        free(nodeToDelete);
        list->tail = NULL;
        list->size = 0;
    } 
    else {
        
        list->tail->next = nodeToDelete->next;
        nodeToDelete->next->prev = list->tail;
        
        free(nodeToDelete);
        list->size--;
    }

    return SUCCESS;
}

Status deleteFromEnd(LinkedList *list){
    if (list == NULL || list->tail == NULL) {
        return ERR_EMPTY_LIST;
    }

    if (list->size == 1) {
        return deleteFromHead(list);
    }

    Node *nodeToDelete = list->tail;       
    Node *head = list->tail->next;         
    Node *prevNode = list->tail->prev;     

    prevNode->next = head;
    head->prev = prevNode;
    
    list->tail = prevNode;

    free(nodeToDelete);
    list->size--;
    return SUCCESS;
}

Status deleteFromPosition(LinkedList *list, int pos) {
    if (list == NULL || list->tail == NULL) {
        return ERR_EMPTY_LIST;
    }

    if (pos <= 0 || pos > list->size) {
        return ERR_INVALID_POS;
    }

    if (pos == 1) {
        return deleteFromHead(list);
    }
    if (pos == list->size) {
        return deleteFromEnd(list);
    }

    Node *nodeToDelete = list->tail->next; 
    
    for (int i = 1; i < pos; i++) {
        nodeToDelete = nodeToDelete->next;
    }

    Node *prevNode = nodeToDelete->prev;
    Node *nextNode = nodeToDelete->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(nodeToDelete);
    list->size--;

    return SUCCESS;
}

void displayList(LinkedList *list){
    if (list == NULL || list->tail == NULL)
    {
        printf("Empty List");
        return;
    }

    Node *temp = list->tail->next;
    do
    {
        printf("%d --> ",temp->data);
        temp = temp->next;
    } while (temp != list->tail->next);
    
    printf("NULL");
}

int getSize(LinkedList *list){
    return list->size;
}

Status deleteList(LinkedList *list){
    if (list == NULL || list->tail == NULL)
    {
        return ERR_EMPTY_LIST;
    }
    
    Node *head = list->tail->next;
    head->prev = NULL;
    list->tail->next = NULL;

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    list->tail = NULL;
    list->size = 0;
    return SUCCESS;
}


bool searchElement(LinkedList *list, int data) {
    if (list == NULL || list->tail == NULL) {
        return false;
    }

    Node *temp = list->tail->next; 
    
    do {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    } while (temp != list->tail->next);

    return false;
}