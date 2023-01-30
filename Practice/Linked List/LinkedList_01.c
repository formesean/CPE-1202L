// Insert a node at the beginning

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // stores the data
    struct node *next; // points to the next node in the linked list / stores the address of the next node
};

struct node *head = NULL; // points to the address of the first node

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // allocates memory for a new node
    newNode->data = data;                                              // assigns the value of data to the data of new node
    newNode->next = head;                                              // connects the new node to the rest of the list
    head = newNode;                                                    // updates the head to point to the new node
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
    int num, x;

    printf("How many numbers do you want to insert? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\nEnter a number: ");
        scanf("%d", &x);
        insert(x);
        display();
    }

    return 0;
}