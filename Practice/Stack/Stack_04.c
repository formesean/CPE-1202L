// using Stack to reverse - inked List implementation

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
    while (top == NULL)
        return;
    top = top->next;
    free(temp);
}

void reverse()
{
    struct node *current, *prev, *next;
    current = top;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

void display(struct node *top)
{
    struct node *current = top;
    if (current == NULL)
        return;
    printf("%d ", current->data);
    display(top->next);
}

int main()
{
    push(2);
    push(4);
    push(6);
    push(8);
    printf("Stack: ");
    display(top);

    pop();
    pop();
    printf("\nStack: ");
    display(top);

    push(6);
    push(8);
    printf("\nStack: ");
    display(top);

    reverse();
    printf("\nStack in reverse: ");
    display(top);

    return 0;
}