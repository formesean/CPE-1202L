// Print linked list using recursion

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

void display(struct node *head)
{
    struct node *current = head;

    if (head == NULL)
        return;

    printf("%d ", head->data);
    display(head->next); // recursive call
}

void reverseDisplay(struct node *head)
{
    struct node *current = head;

    if (head == NULL)
        return;

    reverseDisplay(head->next); // recursive call
    printf("%d ", head->data);
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(8);

    printf("List in order: \n");
    display(head);

    printf("\n\nList in reverse order: \n");
    reverseDisplay(head);

    return 0;
}