#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

// Global variables
int circularQueue[MAX];

int front = -1, rear = -1;

// Function to create an empty circular queue
void Queue()
{
    front = -1;
    rear = -1;
    printf("Circular Queue created.\n");
}

// Function to add an item to the circular queue
void enqueue(int item)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (front == -1)
        front = 0; // Initialize front if queue was empty
    rear = (rear + 1) % MAX;
    circularQueue[rear] = item;
    printf("Enqueued %d\n", item);
}

// Function to remove the front item from the circular queue
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued %d\n", circularQueue[front]);

    if (front == rear)
    {
        // Queue is now empty
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Function to check if the circular queue is empty
int isEmpty()
{
    return (front == -1);
}

// Function to get the size of the circular queue
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

    Queue(); // Initialize the circular queue

    do
    {
        printf("\nCircular Queue Operations:\n");
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
                printf("Circular Queue is empty.\n");
            else
                printf("Circular Queue is not empty.\n");
            break;
        case 4:
            printf("Circular Queue size: %d\n", size());

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