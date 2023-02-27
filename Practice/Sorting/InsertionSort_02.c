// Insertion Sort with Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *sorted = NULL;

void prepend(int data);
void display(struct Node *head);
void sortedInsert(struct Node *newnode);
void insertionSort();

int main()
{
    prepend(5);
    prepend(20);
    prepend(2);

    printf("Unsorted List: ");
    display(head);

    insertionSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}

void prepend(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sortedInsert(struct Node *newnode)
{
    if (sorted == NULL || sorted->data >= newnode->data)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        struct Node *current = sorted;
        while (current->next != NULL && current->next->data < newnode->data)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionSort()
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;

        sortedInsert(current);
        current = next;
    }
    head = sorted;
}