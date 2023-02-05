// Stack implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct node *temp = top;

    if (top == NULL) // stack is empty
        return;
    top = top->next;
    free(temp);
}

void display()
{
    struct node *current = top;

    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    push(3);
    push(6);
    push(9);
    display();

    pop();
    display();

    return 0;
}