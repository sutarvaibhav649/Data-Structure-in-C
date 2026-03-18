#include "doublylinkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

Status insertAtHead(LinkedList *list,int data) {
	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	list->size++;
	return SUCCESS;
}

Status insertAtEnd(LinkedList* list,int data) {
	if (list->head == NULL ) {
		return insertAtHead(list, data);
	}

	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}
	
	newNode->prev = list->tail;
	list->tail->next = newNode;
	list->tail = newNode;

	list->size++;
	return SUCCESS;
}

Status insertAtPosition(LinkedList *list,int data,int pos) {
	if (pos <= 0 || pos > list->size + 1) {
		return ERR_INVALID_POS;
	}

	if (pos == 1) {
		return insertAtHead(list, data);
	}

	if (pos == list->size + 1) {
		return insertAtEnd(list, data);
	}

	Node* temp = list->head;

	for (int i = 1; i < pos - 1;i++) {
		temp = temp->next;
	}

	Node* newNode = createNode(data);
	if (newNode == NULL) {
		return ERR_MALLOC_FAIL;
	}

	newNode->next = temp->next;
	newNode->prev = temp;
	if (temp->next != NULL) {
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	return SUCCESS;
}


Status deleteFromHead(LinkedList *list) {
	if (list->head == NULL) {
		return ERR_EMPTY_LIST;
	}

	if (list->head->next == NULL) {
		Node* temp = list->head;
		list->head = NULL;
		free(temp);
		list->size--;
		return SUCCESS;
	}

	Node* nodeToDelete = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	free(nodeToDelete);
	list->size--;
	return SUCCESS;
}

Status deleteFromEnd(LinkedList *list) {
	if (list->head == NULL) {
		return ERR_EMPTY_LIST;
	}

	if (list->head->next == NULL) {
		return deleteFromHead(list);
	}

	Node* nodeToDelete = list->tail;
	list->tail = nodeToDelete->prev;
	if (list->tail != NULL) {
		list->tail->next = NULL;
	}
	free(nodeToDelete);
	list->size--;
	return SUCCESS;
}

Status deleteFromPosition(LinkedList* list, int pos) {
	if (pos <= 0 || pos > list->size) return ERR_INVALID_POS;
	if (pos == 1) return deleteFromHead(list);
	if (pos == list->size) return deleteFromEnd(list);

	Node* temp = list->head;
	for (int i = 1; i < pos; i++) {
		temp = temp->next;
	}

	temp->prev->next = temp->next;
	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}

	free(temp);
	list->size--;
	return SUCCESS;
}

void displayList(LinkedList* list) {
	if (list->head == NULL) {
		printf("List is empty");
		return;
	}

	Node* temp = list->head;
	while (temp != NULL) {
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

bool searchElement(LinkedList *list,int element) {
	if (list->head == NULL) {
		printf("List is empty");
		return false;
	}

	Node* temp = list->head;
	while (temp != NULL) {
		if (temp->data == element) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

Status deleteList(LinkedList *list) {
	if (list->head == NULL) {
		return ERR_EMPTY_LIST;
	}

	Node* temp = list->head;
	while (temp != NULL) {
		Node* nodeToDelete = temp;
		temp = temp->next;
		free(nodeToDelete);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return SUCCESS;
}