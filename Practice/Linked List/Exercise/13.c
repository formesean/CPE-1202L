// Write a program in C to create and display a doubly linked list.

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

void display()
{
    struct node *current = head;
    int i = 0;

    printf("\nData entered on the list are :\n");
    while (current != NULL)
    {
        printf("node %d : %d\n", i + 1, current->data);
        i++;
        current = current->next;
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