#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data);
void insert(struct Node **head, int data);
void display(struct Node *head);
void bubbleSort(struct Node **head);
void freeList(struct Node *head);

int main()
{
    struct Node *head = NULL;

    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 1);
    insert(&head, 10);
    insert(&head, 3);

    printf("Unsorted List: ");
    display(head);

    bubbleSort(&head);
    printf("Sorted List: ");
    display(head);

    return 0;
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

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

void bubbleSort(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node *prev, *current, *next;
    int swap;

    do
    {
        swap = 0;
        prev = NULL;
        current = *head;
        next = current->next;

        while (next != NULL)
        {
            if (current->data > next->data)
            {
                swap = 1;
                current->next = next->next;
                next->next = current;

                if (prev == NULL)
                    *head = next;
                else
                    prev->next = next;

                prev = next;
                next = current->next;
            }
            else
            {
                prev = current;
                current = next;
                next = next->next;
            }
        }

    } while (swap);
}

void freeList(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}