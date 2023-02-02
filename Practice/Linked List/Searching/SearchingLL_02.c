// Searching element in Linked List using Recursive

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display()
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int searchElement(struct node *head, int item, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == item)
        return index;

    index++;

    return searchElement(head->next, item, index);
}

int main()
{
    int item, index;

    insert(1);
    insert(2);
    insert(3);
    insert(4);

    printf("Linked List: ");
    display();

    printf("Enter element to search: ");
    scanf("%d", &item);
    fflush(stdin);

    index = searchElement(head, item, 0);

    if (index == -1)
        printf("Element not found!");
    else
        printf("Element found at position: %d", index + 1);

    return 0;
}