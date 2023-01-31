// Reverse a linked list using recursion

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

void reverse(struct node *current)
{
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    reverse(current->next);

    struct node *temp = current->next;
    temp->next = current;
    current->next = NULL;
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

    printf("\nList in order: \n");
    display();

    printf("\n\nList in reverse order: \n");
    reverse(head);
    display();

    return 0;
}