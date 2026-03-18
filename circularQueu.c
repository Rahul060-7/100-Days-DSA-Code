#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

void enqueue(int value) {
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    }
    else if (rear == size - 1 && front != 0) {
        rear = 0; 
    }
    else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int data = queue[front];

    if (front == rear) { 
        front = rear = -1;
    }
    else if (front == size - 1) {
        front = 0; 
    }
    else {
        front++;
    }

    printf("Deleted: %d\n", data);
}


void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < size; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}


int main() {
    int choice, value;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;

            case 2:
                dequeue();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}