// using Stack to reverse - Array implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct Stack
{
    int top;
    char string[MAX_LEN];
};

void push(struct Stack *stack, char str)
{
    if (stack->top == MAX_LEN - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    stack->string[++stack->top] = str;
}

char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack->string[stack->top--];
}

void reverse(char str[])
{
    struct Stack stack;
    stack.top = -1;
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        push(&stack, str[i]);
    }

    for (i = 0; i < strlen(str); i++)
    {
        str[i] = pop(&stack);
    }
}

int main()
{
    char str[MAX_LEN];

    printf("Enter a string: ");
    gets(str);

    reverse(str);
    printf("Reverse: %s", str);

    return 0;
}