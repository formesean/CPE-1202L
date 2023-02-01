// write a program in C to delete a node from the middle of Singly Linked List

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

void delete(int pos)
{
    struct node *current, *prev;
    current = head;
    prev = head;
    int count = 1;

    if (head == NULL)
    {
        printf("\nThere are no node in the list.\n");
    }
    else
    {
        while (current != NULL)
        {
            if (pos == count)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            prev = current;
            current = current->next;
            count++;
        }
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
    int num, pos;

    printf("Input the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);
    printf("\nData entered in the list are :\n");
    display(num);

    printf("\nInput the position of node to delete : ");
    scanf("%d", &pos);
    fflush(stdin);

    if (pos <= 1 || pos >= num)
        printf("\nDeletion unsuccesful! Try again.\n");

    if (pos > 1 && pos < num)
    {
        delete (pos);
        printf("\nDeletion completed successfully.\n");
    }

    printf("\nThe new list are :\n");
    display();

    return 0;
}