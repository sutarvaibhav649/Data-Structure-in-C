#include "circularlinkedlist.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    LinkedList myList = { .tail = NULL, .size = 0 };

    int choice, data, pos;
    Status result;
    bool boolResult;

    printf("Welcome to the Linked List Program...\n");

    while (true) {
        printf("\n1. Insert At Head\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Position\n");
        printf("4. Delete From Head\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Position\n");
        printf("7. Display List\n");
        printf("8. Get Size\n");
        printf("9. Search Element\n");
        printf("10. Exit the program\n");
        printf("Enter your choice: ");

        int rc = scanf("%d", &choice);
        if (rc != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("Data: ");
            scanf("%d", &data);
            result = insertAtHead(&myList, data);
            if (result == ERR_MALLOC_FAIL) printf("Memory Allocation Failed\n");
            else printf("Inserted\n");
            break;

        case 2:
            printf("Data: ");
            scanf("%d", &data);
            result = insertAtEnd(&myList, data);
            if (result == ERR_MALLOC_FAIL) printf("Memory Allocation Failed\n");
            else printf("Inserted\n");
            break;

        case 3:
            printf("Data: ");
            scanf("%d", &data);
            printf("Position: ");
            scanf("%d", &pos);
            result = insertAtPosition(&myList, data, pos);
            if (result == ERR_MALLOC_FAIL) printf("Memory Allocation Failed\n");
            else if (result == ERR_INVALID_POS) printf("Invalid Position\n");
            else printf("Inserted\n");
            break;

        case 4:
            result = deleteFromHead(&myList);
            if (result == ERR_EMPTY_LIST) printf("List is already empty\n");
            else printf("Deleted from Head\n");
            break;

        case 5:
            result = deleteFromEnd(&myList);
            if (result == ERR_EMPTY_LIST) printf("List is already empty\n");
            else printf("Deleted from End\n");
            break;

        case 6:
            printf("Position: ");
            scanf("%d", &pos);
            result = deleteFromPosition(&myList, pos);
            if (result == ERR_EMPTY_LIST) printf("List is empty\n");
            else if (result == ERR_INVALID_POS) printf("Invalid Position\n");
            else printf("Deleted from Position %d\n", pos);
            break;

        case 7:
            displayList(&myList);
            break;

        case 8:
            printf("Current Size: %d\n", myList.size);
            break;

        case 9:
            printf("Data to search: ");
            scanf("%d", &data);
            boolResult = searchElement(&myList, data);
            if (boolResult) printf("Element %d is present in the list\n", data);
            else printf("Element %d is not present\n", data);
            break;

        case 10:
            deleteList(&myList);
            printf("Exiting Program...\n");
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
    return 0;
}