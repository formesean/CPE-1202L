// Write a program in C to create and display Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data, int num)
{
    int x;
    struct node *current = head;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &x);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
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

void display(int num)
{
    struct node *current = head;

    while (current != NULL)
    {
        for (int i = 0; i < num; i++)
        {
            printf("Data = %d\n", current->data);
            current = current->next;
        }
    }
}

int main()
{
    int num, data;

    printf("Input the number of nodes : ");
    scanf("%d", &num);

    insert(data, num);
    printf("\nData entered in the list :\n");
    display(num);

    return 0;
}