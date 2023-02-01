// create a singly linked list of n nodes and count the number of nodes

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

void display()
{
    struct node *current = head;
    int count = 0;

    while (current != NULL)
    {
        printf("Data = %d\n", current->data);
        current = current->next;
        count++;
    }

    printf("\nTotal number of nodes = %d", count);
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

    return 0;
}