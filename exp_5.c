#include <stdio.h>
#include <stdlib.h>

struct stu {
    int info;
    struct stu *next;
} *p, *temp, *head = NULL;

struct stu *newNode(int a);

void addNodeFIFO(struct stu *node);

void traverse();

int main() {
    int a, ch = 1;

    while (ch != 0) {
        printf("Enter a number: ");
        scanf("%d", &a);
        p = newNode(a);
        addNodeFIFO(p);
        printf("Enter 0 to stop, 1 to add more: ");
        scanf("%d", &ch);
    }

    // traversing
    printf("Final result: \n");
    traverse(head);

    return 0;
}

struct stu *newNode(int a) {
    p = (struct stu *) malloc(sizeof(struct stu));
    p->info = a;
    p->next = NULL;
    return p;
}

void addNodeFIFO(struct stu *node) {
    temp = head;
    if (head == NULL) {
        head = node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void traverse() {
    temp = head;
    while (temp != NULL) {
        printf("The value is: %d \n", temp->info);
        temp = temp->next;
    }
}
