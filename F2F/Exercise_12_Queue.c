#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
    int size;
};

void initQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error: Out of memory\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is underflow.\n");
        return -1;
    }
    else
    {
        struct Node *temp = queue->front;

        int data = temp->data;
        queue->front = temp->next;
        free(temp);
        queue->size--;

        return data;
    }
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is underflow.\n");
        return;
    }
    else
    {
        struct Node *temp = queue->front;
        printf("Queue: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Queue queue;
    initQueue(&queue);

    int choice, data;

    while (1)
    {
        printf("\n");
        printf("=====================================\n");
        printf("                MENU                 \n");
        printf("=====================================\n");
        printf("1. Add customer to queue\n");
        printf("2. Remove customer from queue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("=====================================\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter customer ID: ");
            if (scanf("%d", &data) != 1)
            {
                printf("Invalid input. Try again.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            system("cls");
            enqueue(&queue, data);
            break;
        case 2:
            data = dequeue(&queue);
            if (data != -1)
            {
                printf("Removed customer with ID %d\n", data);
            }
            system("cls");
            break;
        case 3:
            system("cls");
            display(&queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
