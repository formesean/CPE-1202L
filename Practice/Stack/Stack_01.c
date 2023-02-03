// Array implementation of Stack

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int arr[MAX_SIZE];
int Top = -1;

void push(int data)
{
    if (Top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    Top++;
    arr[Top] = data;
}

void pop()
{
    if (Top == -1)
    {
        printf("Error: stack is empty\n");
        return;
    }
    Top--;
}

int top()
{
    return arr[Top];
}

void display()
{
    printf("Stack: ");
    for (int i = 0; i <= Top; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    pop();
    pop();
    display();

    push(8);
    push(6);
    display();

    pop();
    display();
    return 0;
}