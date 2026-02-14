#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the deque
// Global variables
int deque[MAX];
int front = -1, rear = -1;
// Function to create an empty deque
void Queue()
{
    front = -1;
    rear = -1;
    printf("Deque created.\n");
}
// Function to insert an item at the front of the deque

void enqueueFront(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full. Cannot enqueue %d at front.\n", item);
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front = front - 1;
    }
    deque[front] = item;
    printf("Enqueued %d at front\n", item);
}
// Function to insert an item at the rear of the deque
void enqueueRear(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full. Cannot enqueue %d at rear.\n", item);
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    deque[rear] = item;
    printf("Enqueued %d at rear\n", item);
}
// Function to delete an item from the front of the deque
void dequeueFront()
{
    if (front == -1)
    {
        printf("Deque is empty. Cannot dequeue from front.\n");
        return;
    }
    printf("Dequeued %d from front\n", deque[front]);
    if (front == rear)
    {
        front = -1;

        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}
// Function to delete an item from the rear of the deque
void dequeueRear()
{
    if (rear == -1)
    {
        printf("Deque is empty. Cannot dequeue from rear.\n");
        return;
    }
    printf("Dequeued %d from rear\n", deque[rear]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear = rear - 1;
    }
}
// Function to check if the deque is empty
int isEmpty()
{
    return (front == -1);
}
// Function to get the size of the deque
int size()
{
    if (isEmpty())
        return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}
// Main function with switch-case to repeatedly call the operations
int main()
{
    int choice, item;
    Queue(); // Initialize the deque

    do
    {
        printf("\nDeque Operations:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Check if Deque is Empty\n");
        printf("6. Get Deque Size\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to enqueue at front: ");
            scanf("%d", &item);
            enqueueFront(item);
            break;
        case 2:
            printf("Enter the item to enqueue at rear: ");
            scanf("%d", &item);
            enqueueRear(item);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            if (isEmpty())
                printf("Deque is empty.\n");
            else
                printf("Deque is not empty.\n");
            break;
        case 6:
            printf("Deque size: %d\n", size());
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}