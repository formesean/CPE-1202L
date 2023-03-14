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
void shellSort(struct Node **head);

int main()
{
    struct Node *head = NULL;

    append(&head, 3);
    append(&head, 7);
    append(&head, 1);
    append(&head, 9);
    append(&head, 2);

    printf("Unsorted List: ");
    display(head);

    shellSort(&head);

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

void shellSort(struct Node **head)
{
    struct Node *temp = *head;
    int len = 0, gap;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            struct Node *current = *head;
            int currentData;

            // move current to ith element
            for (int j = 0; j < i; j++)
                current = current->next;

            // compare and swap with the previous elements in the gaps
            for (int j = i - gap; j >= 0; j -= gap)
            {
                struct Node *prev = *head;

                for (int k = 0; k < j; k++)
                    prev = prev->next;

                if (prev->data > current->data)
                {
                    currentData = current->data;
                    current->data = prev->data;
                    prev->data = currentData;
                    current = prev;
                }
                else
                    break;
            }
        }
    }
}
