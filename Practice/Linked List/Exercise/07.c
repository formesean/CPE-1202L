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
    struct node *current;

    if (head == NULL)
    {
        printf("\nThere are no node in the list.\n");
    }
    else
    {
        current = head;
        head = head->next;
        printf("\nData of node 1 which is being deleted is : %d\n", current->data);
        free(current);
    }
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
    display(num);

    delete ();

    printf("\nData, after deletion of first node :\n");
    display();

    return 0;
}