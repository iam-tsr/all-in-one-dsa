#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue
// Global variables
int queue[MAX];
int front = -1, rear = -1;
// Function to create an empty queue
void Queue()
{
    front = -1;
    rear = -1;
    printf("Queue created.\n");
}
// Function to add an item to the rear of the queue
void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (front == -1)
        front = 0; // Initialize front if queue was empty
    queue[++rear] = item;
    printf("Enqueued %d\n", item);
}
// Function to remove the front item from the queue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = -1; // Reset queue when all elements are dequeued
        rear = -1;
    }
}
// Function to check if the queue is empty
int isEmpty()
{

    return (front == -1 || front > rear);
}
// Function to get the size of the queue
int size()
{
    if (isEmpty())
        return 0;
    return rear - front + 1;
}
// Main function with switch-case to repeatedly call the operations
int main()
{
    int choice, item;
    Queue(); // Initialize the queue
    do
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Queue is Empty\n");
        printf("4. Get Queue Size\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty())
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 4:
            printf("Queue size: %d\n", size());
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:

            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}