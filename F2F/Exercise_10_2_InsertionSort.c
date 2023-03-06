#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *sorted = NULL;

struct Node *createNode(int data);
void insert(int data);
void display(struct Node *head);
void sortedInsert(struct Node *newnode);
void insertionSort();
int binarySearch(struct Node *head, int key);

int main()
{
    int num, count = 0, key;

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
        insert(num);
        count++;
    }

    printf("\nUnsorted List: ");
    display(head);

    printf("\n");
    insertionSort(head);

    printf("\nSorted List: ");
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

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *current = head;

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
    int pass = 0;

    while (current != NULL)
    {
        struct Node *next = current->next;

        sortedInsert(current);
        current = next;

        printf("Pass %d: ", ++pass);
        display(sorted);
    }
    head = sorted;
}

int binarySearch(struct Node *head, int key)
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
        int mid = (low + high) / 2;
        struct Node *current = head;
        for (int i = 0; i < mid; i++)
        {
            current = current->next;
        }
        if (current->data == key)
        {
            return mid;
        }
        else if (current->data < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
