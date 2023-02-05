// Check for balance parentheses using Stack

// ()      BALANCED?   YES
// {()()   BALANCED?   NO
// {)      BALANCED?   NO

// no. of opening = no. of closing
// Last Open, First Closed
// from left to right
// if opening symbol, add to a list
// if closing symbol, remove last opening symbol in list
// program ends with an empty list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int Top = -1;

void push(char c)
{
    if (Top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow.\n");
        return;
    }
    stack[++Top] = c;
}

void pop()
{
    if (Top == -1)
    {
        printf("Error: stack is empty.\n");
        return;
    }
    Top--;
}

int checkBalance(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char c = stack[Top];

            if (Top == -1)
                return 0;

            if (str[i] == ')' && c != '(')
                return 0;

            if (str[i] == '}' && c != '{')
                return 0;

            if (str[i] == ']' && c != '[')
                return 0;

            pop();
        }
    }
    return (Top == -1) ? 1 : 0;
}

int main()
{
    char str[MAX_SIZE];

    printf("Enter the expression: ");
    scanf("%s", str);

    if (checkBalance(str))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}