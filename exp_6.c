#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }

    int value = queue->arr[queue->front];

    if (queue->front == queue->rear)
        initialize(queue);
    else
        queue->front = (queue->front + 1) % MAX_SIZE;

    return value;
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, element;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&queue));
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
