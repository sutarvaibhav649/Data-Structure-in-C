#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Status insertAtHead(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return ERR_MALLOC_FAIL;

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return SUCCESS;
}

Status insertAtEnd(LinkedList* list, int data) {
    if (list->head == NULL) {
        return insertAtHead(list, data);
    }

    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = createNode(data);
    if (newNode == NULL) return ERR_MALLOC_FAIL;

    temp->next = newNode;
    list->size++;
    return SUCCESS;
}

Status insertAtPosition(LinkedList* list, int data, int pos) {
    if (pos <= 0 || pos > list->size + 1) return ERR_INVALID_POS;
    if (pos == 1) return insertAtHead(list, data);
    if (pos == list->size + 1) return insertAtEnd(list, data);

    Node* temp = list->head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = createNode(data);
    if (newNode == NULL) return ERR_MALLOC_FAIL;

    newNode->next = temp->next;
    temp->next = newNode;
    list->size++;
    return SUCCESS;
}

Status deleteFromHead(LinkedList* list) {
    if (list->head == NULL) return ERR_LIST_EMPTY;

    Node* nodeToDelete = list->head;
    list->head = list->head->next;
    free(nodeToDelete);
    list->size--;
    return SUCCESS;
}

Status deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) return ERR_LIST_EMPTY;
    if (list->head->next == NULL) return deleteFromHead(list);

    Node* temp = list->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    list->size--;
    return SUCCESS;
}

Status deleteFromPosition(LinkedList* list, int pos) {
    if (pos <= 0 || pos > list->size) return ERR_INVALID_POS;
    if (pos == 1) return deleteFromHead(list);
    if (pos == list->size) return deleteFromEnd(list);

    Node* temp = list->head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    list->size--;
    return SUCCESS;
}

void displayList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return;
    }
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

bool searchElement(LinkedList* list, int element) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == element) return true;
        temp = temp->next;
    }
    return false;
}

Status deleteList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->size = 0;
    return SUCCESS;
}