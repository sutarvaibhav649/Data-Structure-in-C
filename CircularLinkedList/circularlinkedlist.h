#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <stdbool.h>

typedef enum Status {
	SUCCESS = 1,
	ERR_MALLOC_FAIL = -1,
	ERR_EMPTY_LIST = -3,
	ERR_INVALID_POS = -2
}Status;

typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct LinkedList {
	Node* tail;
	int size;
}LinkedList;


// Prototypes
Node* createNode(int data);
Status insertAtHead(LinkedList* list, int data);
Status insertAtEnd(LinkedList* list, int data);
Status insertAtPosition(LinkedList* list, int data, int pos);
Status deleteFromHead(LinkedList* list);
Status deleteFromEnd(LinkedList* list);
Status deleteFromPosition(LinkedList* list, int pos);
void displayList(LinkedList* list);
bool searchElement(LinkedList* list, int element);
Status deleteList(LinkedList* list);

#endif // !CIRCULAR_LINKED_LIST_H
