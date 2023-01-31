// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *getNewNode(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int x)
{
    struct node *newNode = getNewNode(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void display()
{
    struct node *current = head;

    printf("List:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseDisplay()
{
    struct node *current = head;

    if (current == NULL) // exits if list is empty
        return;

    while (current->next != NULL) // traverse to the last node
    {
        current = current->next;
    }

    printf("Reversed List:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    display();
    reverseDisplay();

    return 0;
}