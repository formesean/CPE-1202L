// Insert a node at nth position

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // stores the data
    struct node *next; // points to the next node in the linked list / stores the address of the next node
};

struct node *head = NULL;

void insert(int data, int n)
{
    struct node *newNode1 = (struct node *)malloc(sizeof(struct node)); // allocates memory for a new node
    newNode1->data = data;                                              // assigns the value of data to the data of new node
    newNode1->next = NULL;

    if (n == 1)
    {
        newNode1->next = head;
        head = newNode1;
        return;
    }

    struct node *newNode2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        newNode2 = newNode2->next;
    }

    newNode1->next = newNode2->next;
    newNode2->next = newNode1;
}

void display()
{
    struct node *current = head;

    printf("The list: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    insert(2, 1);
    insert(3, 2);
    insert(1, 3);
    insert(4, 3);
    display();

    return 0;
}