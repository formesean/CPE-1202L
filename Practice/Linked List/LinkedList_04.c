// Reverse a linked list

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
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // allocates memory for a new node
    newNode->data = data;                                              // assigns the value of data to the data of new node
    newNode->next = head;                                              // connects the new node to the rest of the list
    head = newNode;                                                    // updates the head to point to the new node
}

void reverse()
{
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next; // stores the address of the nestruct xt node to the current node
        current->next = prev; // cuts the link and current node address becomes prev
        prev = current;       // prev becomes the address and moves to current
        current = next;       // current becomes the address and moves to next
    }

    head = prev;
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