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
    int num, count = 0;

    printf("Enter at least 10 numbers (press -1 to stop):\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == -1 && count >= 10)
            break;
        if (num == -1 && count < 10)
        {
            printf("Please enter at least 10 numbers!\n");
            continue;
        }
        insert(&head, num);
        count++;
    }

    printf("\nUnsorted List: ");
    display(head);

    printf("\n");

    bubbleSort(&head);
    printf("\nSorted List: ");
    display(head);

    freeList(head);

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
    int pass = 1;

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

        printf("Pass %d: ", pass++);
        display(*head);

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