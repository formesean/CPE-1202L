// Circular Singly Linked list - Insertion at the Tail/End

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
    {
        temp = temp->next;
    }
    temp->next = newNode;
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
    int data, num;

    // printf("Enter number of nodes: ");
    // scanf("%d", &num);

    // for (int i = 0; i < num; i++)
    // {
    //     printf("Enter number: ");
    //     scanf("%d", &data);
    //     insert(data);
    // }

    insert(3);
    insert(6);
    insert(9);
    insert(12);

    display();

    return 0;
}