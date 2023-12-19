#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
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
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with a given key from the list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the key is found at the beginning
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present in the list
    if (temp == NULL) {
        printf("Key not found in the linked list.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the elements of the linked list
void display(struct Node* head) {
    printf("Linked List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initializing an empty linked list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    // Display the linked list
    printf("Initial ");
    display(head);

    // Delete a node with key 20
    deleteNode(&head, 20);

    // Display the updated linked list
    printf("Updated ");
    display(head);

    return 0;
}
