#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head){
    struct Node *ptr = head;

    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head->next;

    
}

int main() {

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = head;

    Traversal(head);

    return 0;
}