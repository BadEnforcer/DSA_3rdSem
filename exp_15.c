#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct AdjList* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    for (int i = 0; i < vertices; ++i) graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BFS(struct Graph* graph, int start) {
    int* visited = (int*)calloc(graph->vertices, sizeof(int));
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->array[current].head;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int start) {
    int* visited = (int*)calloc(graph->vertices, sizeof(int));
    DFSUtil(graph, start, visited);
    free(visited);
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("BFS Traversal: ");
    BFS(graph, 0);
    printf("\n");

    printf("DFS Traversal: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
