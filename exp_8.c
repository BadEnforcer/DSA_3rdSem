#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void initialize(struct CircularQueue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == NULL);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct CircularQueue* queue, int value) {
    struct Node* newNode = createNode(value);

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        newNode->next = newNode; // Circular link
    } else {
        queue->rear->next = newNode;
        newNode->next = queue->front;
        queue->rear = newNode;
    }

    printf("%d enqueued into the circular queue.\n", value);
}

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue underflow. Cannot dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }

    int value;
    struct Node* temp = queue->front;

    if (queue->front == queue->rear) {
        value = temp->data;
        queue->front = queue->rear = NULL;
    } else {
        value = temp->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    free(temp);
    return value;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    struct Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    // Enqueue some default values
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display the initial state of the circular queue
    display(&queue);

    // Dequeue an element
    int dequeuedValue = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedValue);

    // Display the updated state of the circular queue
    display(&queue);

    return 0;
}
