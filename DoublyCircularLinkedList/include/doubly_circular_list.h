#ifndef DOUBLY_CIRCULAR_LIST_H
#define DOUBLY_CIRCULAR_LIST_H
#include <stdbool.h>
typedef enum Status{
    SUCCESS = 1,
    ERR_MALLOC_FAIL = -1,
    ERR_INVALID_POS = -2,
    ERR_EMPTY_LIST = -3

}Status;

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct LinkedList
{
    Node *tail;
    int size;
}LinkedList;

Node *createNode(int data);
// methods for the Circular Doubly Linked List
Status insertAtHead(LinkedList *list,int data);
Status insertAtEnd(LinkedList *list,int data);
Status insertAtPosition(LinkedList *list,int data,int pos);
Status deleteFromHead(LinkedList *list);
Status deleteFromEnd(LinkedList *list);
Status deleteFromPosition(LinkedList *list,int pos);
void displayList(LinkedList *list);
int getSize(LinkedList *list);
Status deleteList(LinkedList *list);
bool searchElement(LinkedList *list, int data);

#endif