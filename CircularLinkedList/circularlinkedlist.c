#include "circularlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

Status insertAtHead(LinkedList *list,int data) {
	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}
	if (list->tail == NULL) {
		list->tail = newNode;
		list->tail->next = list->tail;
	}
	else {
		newNode->next = list->tail->next;
		list->tail->next = newNode;
	}
	list->size++;
	return SUCCESS;
}

Status insertAtEnd(LinkedList *list,int data) {
	if (list->tail == NULL) {
		return insertAtHead(list,data);
	}
	
	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}
	
	newNode->next = list->tail->next;
	list->tail->next = newNode;
	list->tail = newNode;
	list->size++;
	return SUCCESS;
}

Status insertAtPosition(LinkedList* list, int data, int pos) {
	if (pos <= 0 || pos > list->size + 1) {
		return ERR_INVALID_POS;
	}

	if (pos == 1) {
		return insertAtHead(list, data);
	}

	if (pos == list->size+1) {
		return insertAtEnd(list, data);
	}

	Node* temp = list->tail->next;
	for (int i = 1; i < pos - 1;i++) {
		temp = temp->next;
	}

	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}

	newNode->next = temp->next;
	temp->next = newNode;
	list->size++;
	return SUCCESS;
}

Status deleteFromHead(LinkedList* list) {
	if (list->tail == NULL) return ERR_EMPTY_LIST;

	Node* head = list->tail->next;

	if (list->size == 1) { 
		list->tail = NULL;
	}
	else {
		list->tail->next = head->next; 
	}

	free(head);
	list->size--;
	return SUCCESS;
}

Status deleteFromEnd(LinkedList* list) {
	if (list->tail == NULL) return ERR_EMPTY_LIST;
	if (list->size == 1) return deleteFromHead(list);

	Node* temp = list->tail->next; 
	while (temp->next != list->tail) {
		temp = temp->next;
	}

	Node* nodeToDelete = list->tail;
	temp->next = list->tail->next; 
	list->tail = temp;             

	free(nodeToDelete);
	list->size--;
	return SUCCESS;
}

Status deleteFromPosition(LinkedList* list, int pos) {
	if (pos <= 0 || pos > list->size) {
		return ERR_INVALID_POS;
	}

	if (pos == 1) {
		return deleteFromHead(list);
	}

	if (pos == list->size) {
		return deleteFromEnd(list);
	}
	Node* temp = list->tail->next;
	for (int i = 1; i < pos - 1;i++) {
		temp = temp->next;
	}

	Node* nodeToDelete = temp->next;
	temp->next = nodeToDelete->next;
	free(nodeToDelete);
	list->size--;
	return SUCCESS;
}

void displayList(LinkedList* list) {
	if (list->tail == NULL) {
		printf("Empty List");
		return;
	}

	Node* temp = list->tail->next;
	do {
		printf("%d --> ", temp->data);
		temp = temp->next;
	} while (temp != list->tail->next);
	printf("HEAD");
}

bool searchElement(LinkedList *list,int element) {
	if (list->tail == NULL) {
		printf("Empty List");
		return false;
	}

	Node* temp = list->tail->next;
	do {
		if (temp->data == element) {
			return true;
		}
		temp = temp->next;
	} while (temp != list->tail);
	return false;
}

Status deleteList(LinkedList* list) {
	if (list->tail == NULL) return ERR_EMPTY_LIST;

	Node* current = list->tail->next; 
	list->tail->next = NULL; 

	while (current != NULL) {
		Node* next = current->next;
		free(current);
		current = next;
	}

	list->tail = NULL;
	list->size = 0;
	return SUCCESS;
}