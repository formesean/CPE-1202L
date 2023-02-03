// Write a program in C to insert a new node at any position in a doubly linked

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(int num)
{
    int data;
    struct node *current = head;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &data);
        fflush(stdin);

        struct node *newNode = createNode(data);

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

void newInsert(int data, int pos)
{
    struct node *newNode = createNode(data);

    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
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
    int num, data, pos;

    printf("Input the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);
    printf("\nData entered on the list are :\n");
    display();

    printf("\nInput the position ( 1 to %d ) to insert a new node : ", num + 1);
    scanf("%d", &pos);
    fflush(stdin);

    printf("Input data for the position %d : ", pos);
    scanf("%d", &data);
    fflush(stdin);

    newInsert(data, pos);
    printf("\nAfter insertion the new list are :\n");
    display();

    return 0;
}