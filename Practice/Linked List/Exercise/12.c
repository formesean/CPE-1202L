// Write a C program to convert a Singly Linked list into a array and returns it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        if (current == NULL)
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

int *linkedListToArray(struct node *head, int *size)
{
    struct node *current = head;
    int count = 0, i = 0;

    printf("The linked list: ");

    // Counts the number of nodes in the linked list
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    int *array = (int *)malloc(count * sizeof(int));
    current = head;

    // Copy the values of the nodes in the linked list
    while (current != NULL)
    {
        array[i++] = current->data;
        current = current->next;
    }

    *size = count;
    return array;
}

int main()
{
    int num, size;

    printf("Linked List: Convert a Singly Linked list into a array\n");
    printf("-------------------------------------------------------------\n");

    printf("Enter the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);

    printf("\nReturn data entered in the list as a array:\n");
    int *array = linkedListToArray(head, &size);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    free(array);

    return 0;
}