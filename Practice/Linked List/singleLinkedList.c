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

void delete(int data)
{
    struct node *current = head;
    struct node *previous = NULL;

    while (current != NULL && current->data != data) // finds the node with the data value
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Data not Found!\n");
    }
    else
    {
        if (previous == NULL)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next; // deletes current node, updates next pointer of the previous node to next pointer of the current node
        }
        free(current);
    }
}

void display()
{
    struct node *current = head;

    // while (current != NULL)
    // {
    //     printf("%d ", current->data);
    //     current = current->next;
    // }
    // printf("\n");

    if (current == NULL)
    {
        printf("\nThe linked list is empty!\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    int num, option;

    while (1)
    {
        printf("\nEnter a number: ");
        scanf("%d", &num);

        printf("\nWould you like to Insert(1) or Delete(0) the number or Exit(-1)? ");
        scanf("%d", &option);

        if (option == 1)
        {
            insert(num);
            display();
        }
        else if (option == 0)
        {
            delete (num);
            display();
        }
        else if (option == -1)
        {
            break;
        }
        else
        {
            display();
        }
    }

    return 0;
}