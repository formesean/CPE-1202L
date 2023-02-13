// Reverse a linked list - Iterative method

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void reverse()
{
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next; // stores the address of the next node to the current node
        current->next = prev; // cuts the link and current node address becomes prev
        prev = current;       // prev becomes the address and moves to current
        current = next;       // current becomes the address and moves to next
    }

    head = prev;
}

void reverseDisplay()
{
    struct node *current = head;

    printf("The list: ");

    if (head == NULL)
        return;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void display()
{
    struct node *current = head;

    printf("The list: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);

    display();

    reverse();

    display();

    return 0;
}