#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Function to delete a node with a given key from the list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found in the doubly linked list.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

// Function to display the elements of the doubly linked list
void display(struct Node* head) {
    printf("Doubly Linked List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initializing an empty doubly linked list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    // Display the initial doubly linked list
    printf("Initial ");
    display(head);

    // Delete a node with key 20
    deleteNode(&head, 20);

    // Display the updated doubly linked list
    printf("Updated ");
    display(head);

    return 0;
}
