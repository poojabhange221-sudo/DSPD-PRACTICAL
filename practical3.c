//3	Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
#include <stdio.h>
#define MAX 100
char queue[MAX];
int front = -1, rear = -1;
void insert(char element) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert '%c'.\n", element);
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = element;
        printf("'%c' inserted into the queue.\n", element);
    }
}
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Cannot delete.\n");
    } else {
        printf("'%c' deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}
void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nCurrent Queue (front to rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;
    char element;
    printf("\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element into Queue\n");
        printf("2. Delete an element from Queue\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter a character to insert: ");
            scanf(" %c", &element); // space before %c to ignore newline
            insert(element);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}