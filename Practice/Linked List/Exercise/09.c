// write a program in C to delete first node of Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int num)
{
    struct node *current = head;
    int x;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &x);
        fflush(stdin);

        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
}

void delete()
{
    struct node *current, *prev;
    current = head;
    prev = head;

    if (head == NULL)
    {
        printf("\nThere are no node in the list.\n");
    }
    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        if (current == head)
            head = NULL;
        else
            prev->next = NULL;
    }
    free(current);
}

void display()
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
}

int main()
{
    int num, data;

    printf("Input the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);
    printf("\nData entered in the list are :\n");
    display();

    delete ();
    printf("\nThe new list after deletion the last node are :\n");
    display();

    return 0;
}