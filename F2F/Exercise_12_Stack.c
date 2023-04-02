#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node **top, int *data)
{
    if (*top == NULL)
    {
        printf("Error: Stack is underflow.\n");
        return;
    }
    *data = (*top)->data;
    struct Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

int evalPostfix(char *exp)
{
    struct Node *top = NULL;

    while (*exp)
    {
        if (*exp >= '0' && *exp <= '9')
        {
            push(&top, *exp - '0');
        }
        else
        {
            int op2, op1;
            pop(&top, &op2);
            pop(&top, &op1);

            switch (*exp)
            {
            case '+':
                push(&top, op1 + op2);
                break;
            case '-':
                push(&top, op1 - op2);
                break;
            case '*':
                push(&top, op1 * op2);
                break;
            case '/':
                push(&top, op1 / op2);
                break;
            default:
                printf("Error: Invalid operator.\n");
                break;
            }
        }
        exp++;
    }

    int result;
    pop(&top, &result);

    if (top != NULL)
    {
        printf("Error: Invalid operator.\n");
        return 0;
    }
    return result;
}

int main()
{
    char exp[100];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evalPostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
