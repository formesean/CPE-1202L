#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void prepend(struct Node **head, int data);
void append(struct Node **head, int data);
void insert(struct Node **head, int data, int pos);
void edit(struct Node **head, int new_data, int pos);
void delete(struct Node **head, int pos);
void display(struct Node **head);

int main()
{
    struct Node *head = NULL;

    prepend(&head, 1);
    append(&head, 2);
    insert(&head, 3, 2);
    edit(&head, 0, 1);
    delete (&head, 3);
    display(&head);

    return 0;
}

void prepend(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void append(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(struct Node **head, int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void edit(struct Node **head, int new_data, int pos)
{
    struct Node *current = *head;
    int i = 1;

    while (current != NULL && i < pos)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        printf("Error: List is too short");
        return;
    }

    current->data = new_data;
}

void delete(struct Node **head, int pos)
{
    struct Node *newNode = *head;

    if (pos == 1)
    {
        *head = newNode->next;
        free(newNode);
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        newNode = newNode->next;
    }

    struct Node *temp = newNode->next;
    newNode->next = temp->next;
    free(temp);
}

void display(struct Node **head)
{
    struct Node *current = *head;
    printf("\nLinked List: ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}