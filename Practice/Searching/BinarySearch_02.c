#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data);
void display(struct Node *head);
int binarySearch(struct Node *head, int target);

int main()
{
    struct Node *head = NULL;
    int key;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 6);

    display(head);

    printf("\nEnter data to search: ");
    scanf("%d", &key);

    int index = binarySearch(head, key);

    if (index == -1)
        printf("Data not found.\n");
    else
        printf("Data found at index %d.\n", index);

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

void display(struct Node *head)
{
    struct Node *current = head;
    printf("List:");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int binarySearch(struct Node *head, int target)
{
    int low = 0;
    int high = 0;

    struct Node *current = head;
    while (current != NULL)
    {
        current = current->next;
        high++;
    }

    while (low <= high)
    {
        struct Node *current = head;
        int mid = (low + high) / 2;

        for (int i = 0; i < mid; i++)
            current = current->next;

        if (current->data == target)
            return mid;
        else if (current->data > target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}