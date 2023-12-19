#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into a binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the binary search tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL; // Initializing an empty binary search tree

    // Insert nodes into the binary search tree
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 10);
    insert(root, 25);

    // Display the in-order traversal of the binary search tree
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
