#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include<stdbool.h>

typedef enum Status {
	SUCCESS = 1,
	ERR_MALLOC_FAIL = -1,
	ERR_INVALID_POS = -2,
	ERR_EMPTY_LIST = -1
}Status;

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct LinkedList {
	Node* head;
	Node* tail;
	int size;
}LinkedList;

// methods
Node* createNode(int data);
Status insertAtHead(LinkedList *list,int data);
Status insertAtEnd(LinkedList *list,int data);
Status insertAtPosition(LinkedList *list,int data,int pos);
Status deleteFromHead(LinkedList *list);
Status deleteFromEnd(LinkedList *list);
Status deleteFromPosition(LinkedList *list,int pos);

// utility methods
void displayList(LinkedList *list);
bool searchElement(LinkedList *list,int element);
Status deleteList(LinkedList *list);

#endif // !DOUBLY_LINKED_LIST_H
