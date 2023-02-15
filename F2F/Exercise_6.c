#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char lastName[50];
    int jerseyNumber;
    struct Node *next;
};

void prepend(struct Node **head, char *lastName, int jerseyNumber);
void append(struct Node **head, char *lastName, int jerseyNumber);
void insert(struct Node **head, char *lastName, int jerseyNumber, int pos);
void edit(struct Node **head, int new_jerseyNumber, int pos);
void delete(struct Node **head, int pos);
void display(struct Node **head);

int main()
{
    int choice, num, pos, jerseyNumber;
    char lastName[50];
    struct Node *head = NULL;

    do
    {
        printf("\n\nChoose an operation:\n");
        printf("1. Prepend a node\n");
        printf("2. Append a node\n");
        printf("3. Insert a node at a specific position\n");
        printf("4. Edit the data of a node\n");
        printf("5. Delete a node\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            printf("How many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");
                fgets(lastName, 50, stdin);
                printf("Enter player's jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                prepend(&head, lastName, jerseyNumber);
            }
            display(&head);
            break;
        case 2:
            printf("How many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");
                fgets(lastName, 50, stdin);
                printf("Enter player's jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                append(&head, lastName, jerseyNumber);
            }
            display(&head);
            break;
        case 3:
            printf("\nEnter player's last name: ");
            fgets(lastName, 50, stdin);
            printf("Enter player's jersey number: ");
            scanf("%d", &jerseyNumber);
            printf("Enter the position to insert at: ");
            scanf("%d", &pos);
            insert(&head, lastName, jerseyNumber, pos);
            display(&head);
            break;
        case 4:
            printf("\nEnter the position of the player to edit: ");
            scanf("%d", &pos);
            printf("Enter new jersey number: ");
            scanf("%d", &jerseyNumber);
            fflush(stdin);
            edit(&head, jerseyNumber, pos);
            display(&head);
            break;
        case 5:
            printf("\nEnter the position to delete: ");
            scanf("%d", &pos);
            delete (&head, pos);
            display(&head);
            break;
        case 6:
            printf("\nExiting...\n");
            exit(1);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void prepend(struct Node **head, char *lastName, int jerseyNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;
    newNode->next = *head;
    *head = newNode;
}

void append(struct Node **head, char *lastName, int jerseyNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(struct Node **head, char *lastName, int jerseyNumber, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void edit(struct Node **head, int new_jerseyNumber, int pos)
{
    struct Node *current = *head;
    int i = 1;

    while (current != NULL && i < pos)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        printf("Error: List is too short");
        return;
    }

    current->jerseyNumber = new_jerseyNumber;
}

void delete(struct Node **head, int pos)
{
    struct Node *newNode = *head;

    if (pos == 1)
    {
        *head = newNode->next;
        free(newNode);
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        newNode = newNode->next;
    }

    struct Node *temp = newNode->next;
    newNode->next = temp->next;
    free(temp);
}

void display(struct Node **head)
{
    int i = 1;
    struct Node *current = *head;

    printf("\nJersey List:\n");
    while (current != NULL)
    {
        printf("%d.\nName: %sNumber: %d\n\n", i, current->lastName, current->jerseyNumber);
        current = current->next;
        i++;
    }
}