## Modular Linked List Manager in C
A robust, production-style implementation of a Singly Linked List in C. This project demonstrates advanced C concepts including manual memory management, pointer manipulation, and data encapsulation.

## Engineering Highlights
 - Encapsulated Architecture: Instead of global variables, it uses a LinkedList wrapper struct to manage the head pointer and size attribute as a single entity.
 - Safe Pointer Logic: Implements pass-by-reference to modify the list structure across different scopes.
 - Custom Status Codes: Replaces "magic numbers" with a clear Status Enum for error handling (e.g., ERR_MALLOC_FAIL, ERR_INVALID_POS).
 - Defensive Programming: Includes robust input validation to handle non-numeric inputs and prevent infinite loops in the CLI.

## Features
 - Insertion: Head, End, and specific Position.
 - Deletion: Head, End, and specific Position.
 - Search: O(n) search algorithm returning boolean results.
 - Memory Management: Full cleanup utility to prevent memory leaks.
 - Live Metrics: O(1) complexity for retrieving list size.

## Project Structure
```html
		|-SinglyLinkedList
			|-linkedlist.h			-- The interface: contains struct definitions, enums, and function prototypes.
			|-linkedlistimpl.c      -- The logic: contains the implementation of the linked list operations.
			|-main.c				-- The driver: a CLI menu-driven program to interact with the list.
```

## How to Run (Visual Studio)
 - Clone the repository to your local machine.
 - Open the project in Visual Studio 2022.
 - Configure Preprocessor:
 - Right-click Project → Properties.
 - Navigate to C/C++ → Preprocessor.
 - Add _CRT_SECURE_NO_WARNINGS to Preprocessor Definitions.
 - Build and Run (F5).

## Complexity Analysis
|Operations | Time Complexity | Space Complexity |
|---|---|---|
| Insert at Head| O(1)|	O(1)|
| Insert at Tail| O(n) | O(1) |
| Search		| O(n) | O(1) |
| Get Size		| O(1) | O(1) |