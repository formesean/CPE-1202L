// Delete a node at nth position (assuming all position entered is valid, no error handling)

// insert an integer at end of list
// print all elements in the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    struct node *current = head;

    printf("The list: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete(int n)
{
    struct node *newNode1 = head;

    if (n == 1)
    {
        head = newNode1->next; // head now points to the second node
        free(newNode1);
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        newNode1 = newNode1->next; // newNode1 points to (n-1)th node
    }

    struct node *newNode2 = newNode1->next; // nth node
    newNode1->next = newNode2->next;        // (n+1)th node
    free(newNode2);                         // deletes newNode2
}

int main()
{
    int n;
    insertEnd(2);
    insertEnd(4);
    insertEnd(6);
    insertEnd(8);
    insertEnd(10); // List: 2, 4, 6, 8, 10
    display();

    printf("Enter a position: ");
    scanf("%d", &n);

    delete (n);
    display();

    return 0;
}