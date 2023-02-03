// Write a program in C to insert a new node at the beginning in a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert(int num)
{
    int data;
    struct node *current = head;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &data);
        fflush(stdin);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

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

void newInsert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    struct node *current = head;
    int i = 0;

    while (current != NULL)
    {
        printf("node %d : %d\n", i + 1, current->data);
        i++;
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
    printf("\nData entered on the list are :\n");
    display();

    printf("\nInput data for the last node : ");
    scanf("%d", &data);
    fflush(stdin);

    newInsert(data);
    printf("\nAfter insertion the new list are :\n");
    display();

    return 0;
}