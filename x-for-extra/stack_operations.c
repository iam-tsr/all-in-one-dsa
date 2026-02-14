// Stack using Array in C-
#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack is full (Overflow)\n");
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack is empty (Underflow)\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void display() {
    if (top >= 0) {
        printf("Elements in the stack:\n");
        printf("[");
        for (int i = top; i >= 0; i--) {
            printf("%d,", stack[i]);
        }
        printf("]\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int choice, x;
    printf("STACK OPERATIONS USING ARRAY\n");
    printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}