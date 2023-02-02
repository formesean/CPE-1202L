// Write a C program to convert a Singly Linked list into a string and returns it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int num)
{
    struct node *current = head;
    int x;

    for (int i = 0; i < num; i++)
    {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", &x);
        fflush(stdin);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (current == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
}

void linkedListToString(struct node *head, char *str)
{
    struct node *current = head;

    printf("The linked list: ");
    while (current != NULL)
    {
        sprintf(str + strlen(str), "%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int num;
    char str[100];

    printf("Linked List: Convert a Singly Linked list into a string\n");
    printf("-------------------------------------------------------------\n");

    printf("Enter the number of nodes : ");
    scanf("%d", &num);
    fflush(stdin);

    insert(num);

    printf("\nReturn data entered in the list as a string:\n");
    strcpy(str, "");
    linkedListToString(head, str);
    printf("%s", str);

    return 0;
}