// Linear Search with Singly Linked List

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
int search(struct Node *head, int element, int index);
// int search(struct Node *head, int element);

int main()
{
    struct Node *head = NULL;
    int element;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Linked List: ");
    display(head);

    printf("Enter data to search: ");
    scanf("%d", &element);
    fflush(stdin);

    int index = search(head, element, 0);
    // int index = search(head, element);

    if (index == -1)
        printf("Data not found!");
    else
        printf("Data found at position: %d", index + 1);

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

// using recursion
int search(struct Node *head, int element, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == element)
        return index;

    index++;

    return search(head->next, element, index);
}

// using iterative
// int search(struct Node *head, int element)
// {
//     struct Node *current = head;
//     int index = 0;

//     while (current != NULL)
//     {
//         if (current->data == element)
//             return index;

//         current = current->next;
//         index++;
//     }
//     return -1;
// }