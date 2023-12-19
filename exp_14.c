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

// Function to find the node with the minimum value in a binary search tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from a binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
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
    root = createNode(30);
    root->left = createNode(20);
    root->right = createNode(40);
    root->left->left = createNode(10);
    root->left->right = createNode(25);

    // Display the in-order traversal of the binary search tree
    printf("In-order Traversal (Before Deletion): ");
    inOrderTraversal(root);
    printf("\n");

    // Delete a node with key 20
    root = deleteNode(root, 20);

    // Display the updated in-order traversal of the binary search tree
    printf("In-order Traversal (After Deletion): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
