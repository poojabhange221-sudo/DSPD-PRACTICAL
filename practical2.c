//2Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) a. Push an Element on to Stack 
#include <stdio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nCurrent Stack (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
void checkPalindrome() {
    if (top == -1) {
        printf("\nStack is empty. Cannot check palindrome.\n");
        return;
    }

    int i = 0, j = top;
    int isPalindrome = 1;
    while (i < j) {
        if (stack[i] != stack[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }
    if (isPalindrome)
        printf("\nThe stack elements form a Palindrome.\n");
    else
        printf("\nThe stack elements do NOT form a Palindrome.\n");
}

int main() {
    int choice, value;

    printf("\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an element onto Stack\n");
        printf("2. Pop an element from Stack\n");
        printf("3. Check if Stack elements form Palindrome\n");
        printf("4. Display the Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            checkPalindrome();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
	
