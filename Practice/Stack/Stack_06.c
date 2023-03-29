// Check for balance parentheses using Stack with Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

void push(struct Node **top, char c)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Error!");
        return;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

int checkBalance(struct Node *top, char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&top, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char c = top->data;
            
            if (top == NULL)
                return 0;
            if (str[i] == ')' && c != '(')
                return 0;
            if (str[i] == '}' && c != '{')
                return 0;
            if (str[i] == ']' && c != '[')
                return 0;

            pop(&top);
        }
    }
    return (top == NULL) ? 1 : 0;
}

int main()
{
    struct Node *top = NULL;
    char str[100];
    
    printf("Enter the expression: ");
    scanf("%s", str);

    if (checkBalance(top, str))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");
    
    return 0;
}
