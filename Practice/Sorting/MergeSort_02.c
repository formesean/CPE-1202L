#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data);
void append(struct Node **head, int data);
void display(struct Node *head);
void split(struct Node *head, struct Node **left, struct Node **right);

int main()
{
    struct Node *head = NULL;
    return 0;
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int data)
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

void split(struct Node *head, struct Node **left, struct Node **right)
{
    struct Node *fast =
}
