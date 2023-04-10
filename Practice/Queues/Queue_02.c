// Linked List implementation of Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int isEmpty(Node *front, Node *rear)
{
    if (front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

void enqueue(Node **front, Node **rear, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

void dequeue(Node **front, Node **rear)
{
    if (isEmpty(*front, *rear))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = *front;
    if (*front == *rear)
        *front = *rear = NULL;
    else
        *front = (*front)->next;

    free(temp);
}

void display(Node *front, Node *rear)
{
    if (isEmpty(front, rear))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *front = NULL;
    Node *rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);

    display(front, rear);

    dequeue(&front, &rear);

    display(front, rear);

    return 0;
}