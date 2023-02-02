// Write a program in C to create a doubly linked list and display in reverse order.

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
            newNode->prev = current;
            current = current->next;
        }
    }
}

void display()
{
    struct node *current = head;
    int i = 0;

    printf("\nData in reverse order are :\n");

    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("Data in node %d : %d\n", i + 1, current->data);
        i++;
        current = current->prev;
    }
}

int main()
{
    int num;

    printf("Input the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);
    display();

    return 0;
}