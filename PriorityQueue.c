#include <stdio.h>

#define MAX 100


struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};


void init(struct PriorityQueue *pq) {
    pq->size = 0;
}


void insert(struct PriorityQueue *pq, int value, int pr) {
    if (pq->size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    pq->data[pq->size] = value;
    pq->priority[pq->size] = pr;
    pq->size++;

    printf("Element inserted successfully\n");
}


void delete(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    int minIndex = 0;

    
    for (int i = 1; i < pq->size; i++) {
        if (pq->priority[i] < pq->priority[minIndex]) {
            minIndex = i;
        }
    }

    printf("Deleted element: %d (Priority: %d)\n",
           pq->data[minIndex], pq->priority[minIndex]);

    
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }

    pq->size--;
}


void display(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in Priority Queue:\n");
    printf("Value\tPriority\n");

    for (int i = 0; i < pq->size; i++) {
        printf("%d\t%d\n", pq->data[i], pq->priority[i]);
    }
}


int main() {
    struct PriorityQueue pq;
    init(&pq);

    int choice, value, pr;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete (Highest Priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &pr);
                insert(&pq, value, pr);
                break;

            case 2:
                delete(&pq);
                break;

            case 3:
                display(&pq);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}