// Searching element in Linked List using Iterative

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

int searchElement(struct node *head, int item)
{
    struct node *current = head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == item)
            return index;

        current = current->next;
        index++;
    }
    return -1;
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

    index = searchElement(head, item);

    if (index == -1)
        printf("Element not found!");
    else
        printf("Element found at position: %d", index + 1);

    return 0;
}