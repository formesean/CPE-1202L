// Quick Sort with Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data);
struct Node *tail(struct Node *head);
void display(struct Node *head);
struct Node *partition(struct Node *low, struct Node *high);
void quickSort(struct Node *low, struct Node *high);

int main()
{
    struct Node *head = NULL;

    insert(&head, 3);
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 9);
    insert(&head, 2);

    printf("Unsorted List: ");
    display(head);

    quickSort(head, tail(head));

    printf("Sorted List: ");
    display(head);

    return 0;
}

void insert(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;

        while (current->next != NULL)
            current = current->next;

        current->next = newNode;
    }
}

struct Node *tail(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL && current->next != NULL)
        current = current->next;
    return current;
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
struct Node *partition(struct Node *low, struct Node *high)
{
    struct Node *pivot = low;
    struct Node *front = low;
    int temp = 0;

    while (front != NULL && front != high)
    {
        if (front->data < high->data)
        {
            pivot = front;

            temp = low->data;
            low->data = front->data;
            front->data = temp;

            low = low->next;
        }
        front = front->next;
    }
    temp = low->data;
    low->data = high->data;
    high->data = temp;

    return pivot;
}

void quickSort(struct Node *low, struct Node *high)
{
    if (low == high)
        return;

    struct Node *pivot = partition(low, high);

    if (pivot != NULL && pivot->next != NULL)
        quickSort(pivot->next, high);

    if (pivot != NULL && low != pivot)
        quickSort(low, pivot);
}
