// write a program in C to insert a new node at the beginnning of a Singly Linked

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
    int x;
    struct node *current = head;

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

void newInsert(int data, int pos)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
    int num, data, pos;

    do
    {
        printf("\nInput the number of nodes (3 or more) : ");
        scanf("%d", &num);

        if (num < 3)
            printf("Error! number of nodes should be 3 or more!\n");
    } while (num < 3);

    insert(num);
    printf("\nData entered in the list :\n");
    display();

    printf("\nInput data to insert in the middle of the list : ");
    scanf("%d", &data);
    fflush(stdin);

    printf("Input the position to insert new node : ");
    scanf("%d", &pos);
    fflush(stdin);

    if (pos <= 1 || pos >= num)
        printf("\nInsertion unsuccesful! Try again.\n");

    if (pos > 1 && pos < num)
    {
        newInsert(data, pos);
        printf("\nInsertion completed successfully.\n");
    }

    printf("\nData after the inserted in the list are :\n");
    display();

    return 0;
}