#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node
{
    int data;
    struct Node *next;
};
// Function prototypes
void insertLast(struct Node **head, int value);
void insertFirst(struct Node **head, int value);
void insertAtPosition(struct Node **head, int position, int value);
void deleteLast(struct Node **head);
void deleteFirst(struct Node **head);
void deleteAtPosition(struct Node **head, int position);
void updateAtPosition(struct Node *head, int position, int value);
void displayList(struct Node *head);
// Main function
int main()
{
    struct Node *head = NULL;
    int choice, value, position;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert 10 at last.\n");
        printf("2. Insert at first.\n");
        printf("3. Insert at last.\n");
        printf("4. Insert at specific position.\n");
        printf("5. Display the list.\n");
        printf("6. Delete the last element.\n");
        printf("7. Delete the first element.\n");
        printf("8. Update the value at position 2 to 25.\n");
        printf("9. Display the list.\n");
        printf("10. Exit.\n");
        printf("11. Delete at specific position.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertLast(&head, 10);
            break;
        case 2:
            printf("Enter the value to insert at first: ");
            scanf("%d", &value);
            insertFirst(&head, value);
            break;
        case 3:
            printf("Enter the value to insert at last: ");
            scanf("%d", &value);
            insertLast(&head, value);
            break;
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertAtPosition(&head, position, value);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            deleteLast(&head);
            break;
        case 7:
            deleteFirst(&head);
            break;
        case 8:
            updateAtPosition(head, 2, 25);
            break;
        case 9:
            displayList(head);
            break;
        case 10:
            exit(0);
            break;
        case 11:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);

            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
// Function to insert at last
void insertLast(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at last.\n", value);
}
// Function to insert at first
void insertFirst(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at first.\n", value);
}
// Function to insert at a specific position
void insertAtPosition(struct Node **head, int position, int value)
{
    if (position == 1)
    {
        insertFirst(head, value);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}
// Function to delete the last node
void deleteLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("Deleted the last element.\n");
}
// Function to delete the first node
void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;

    *head = (*head)->next;
    free(temp);
    printf("Deleted the first element.\n");
}
// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (position == 1)
    {
        deleteFirst(head);
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted element at position %d.\n", position);
}
// Function to update a value at a specific position
void updateAtPosition(struct Node *head, int position, int value)
{
    struct Node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }
    temp->data = value;
    printf("Updated position %d to value %d.\n", position, value);
}
// Function to display the list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}