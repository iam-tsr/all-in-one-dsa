#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the priority queue
// Global variables

int priorityQueue[MAX];
int front = -1, rear = -1;
// Function to create an empty priority queue
void Queue()
{
    front = -1;
    rear = -1;
    printf("Priority Queue created.\n");
}
// Function to add an item to the priority queue
void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Priority Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    int i;
    if (front == -1)
    {
        // First element
        front = 0;
        rear = 0;
        priorityQueue[rear] = item;
    }
    else
    {
        // Insertion in sorted order (highest priority item at the front)
        for (i = rear; i >= front && priorityQueue[i] < item; i--)
        {
            priorityQueue[i + 1] = priorityQueue[i];
        }
        priorityQueue[i + 1] = item;
        rear++;
    }
    printf("Enqueued %d\n", item);
}
// Function to remove the front item from the priority queue
void dequeue()
{
    if (front == -1)
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued %d\n", priorityQueue[front]);
    front++;
    if (front > rear)
    {
        // Queue is now empty
        front = -1;
        rear = -1;
    }
}
// Function to check if the priority queue is empty
int isEmpty()
{
    return (front == -1);
}
// Function to get the size of the priority queue
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
    Queue(); // Initialize the priority queue
    do
    {
        printf("\nPriority Queue Operations:\n");
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
                printf("Priority Queue is empty.\n");
            else
                printf("Priority Queue is not empty.\n");
            break;
        case 4:
            printf("Priority Queue size: %d\n", size());
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