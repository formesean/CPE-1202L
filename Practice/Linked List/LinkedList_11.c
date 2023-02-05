// Circular Singly Linked List - Deletion at the End/Tail

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

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }
    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
}

void delete()
{
    struct node *current = head;
    while (current->next->next != head)
        current = current->next;
    free(current->next);
    current->next = head;
}

void display()
{
    struct node *current = head;
    printf("Linked List: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    insert(3);
    insert(6);
    insert(9);
    insert(12);
    display();

    delete ();
    delete ();
    display();

    return 0;
}