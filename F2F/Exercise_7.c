#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct Node
{
    char lastName[50];
    int jerseyNumber;
    struct Node *next;
    struct Node *prev;
};

void prepend(struct Node **head, char *lastName, int jerseyNumber);
void append(struct Node **head, char *lastName, int jerseyNumber);
void insert(struct Node **head, char *lastName, int jerseyNumber, int pos);
void edit(struct Node **head, int new_jerseyNumber, int pos);
void delete(struct Node **head, int pos);
void display(struct Node **head);
void displayReverse(struct Node **head);

int main()
{
    int choice, num, pos, jerseyNumber;
    char lastName[50];
    struct Node *head = NULL;

    do
    {
        printf("\n\nChoose an operation:\n");
        printf("\t1. Display Lists\n");
        printf("\t2. Prepend a Jersey\n");
        printf("\t3. Append a Jersey\n");
        printf("\t4. Insert a Jersey at a specific position\n");
        printf("\t5. Edit the data of a Jersey\n");
        printf("\t6. Delete a Jersey\n");
        printf("\t7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("\nHow would you like the list to be displayed?\n");
            printf("\n\t1. Ascending");
            printf("\n\t2. Descending\n");
            printf("\nEnter your choice: ");
            scanf("%d", &num);
            fflush(stdin);

            if (num == 1)
            {
                system("cls");
                display(&head);
                Sleep(1000);
            }
            else if (num == 2)
            {
                system("cls");
                displayReverse(&head);
                Sleep(1000);
            }
            else
            {
                system("cls");
                printf("\nInvalid choice. Please try again.\n");
                Sleep(1000);
            }
            break;
        case 2:
            system("cls");
            printf("\nHow many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");
                gets(lastName);
                printf("Enter player's jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                prepend(&head, lastName, jerseyNumber);
            }
            printf("\nJersey(s) has been added to the list.\n");
            Sleep(1000);
            system("cls");
            break;
        case 3:
            system("cls");
            printf("\nHow many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");
                gets(lastName);
                printf("Enter player's jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                append(&head, lastName, jerseyNumber);
            }
            printf("\nJersey(s) has been added to the list.\n");
            Sleep(1000);
            system("cls");
            break;
        case 4:
            system("cls");
            printf("\nHow many Jersey do you want to insert? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");
                gets(lastName);
                printf("Enter player's jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                printf("Enter the position to insert at: ");
                scanf("%d", &pos);
                fflush(stdin);
                insert(&head, lastName, jerseyNumber, pos);
            }
            printf("\nJersey(s) has been added to the list.\n");
            Sleep(1000);
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\nHow many Jersey do you want to edit? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter the position of the player to edit: ");
                scanf("%d", &pos);
                fflush(stdin);
                printf("Enter new jersey number: ");
                scanf("%d", &jerseyNumber);
                fflush(stdin);
                edit(&head, jerseyNumber, pos);
                printf("\nJersey has been editted.\n");
            }
            Sleep(1000);
            system("cls");
            break;
        case 6:
            system("cls");
            printf("\nEnter the position to delete: ");
            scanf("%d", &pos);
            fflush(stdin);
            delete (&head, pos);
            printf("\nJersey has been deleted from the list.\n");
            Sleep(1000);
            system("cls");
            break;
        case 7:
            system("cls");
            printf("\nExiting...\n");
            Sleep(1000);
            exit(1);
        default:
            system("cls");
            printf("\nInvalid choice. Please try again.\n");
            Sleep(1000);
            system("cls");
        }

    } while (choice != 7);

    return 0;
}

void prepend(struct Node **head, char *lastName, int jerseyNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    (*head)->prev = newNode;
    *head = newNode;
    system("cls");
}

void append(struct Node **head, char *lastName, int jerseyNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *lastNode = *head;

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (lastNode->next != NULL)
        lastNode = lastNode->next;

    lastNode->next = newNode;
    newNode->prev = lastNode;
    system("cls");
}

void insert(struct Node **head, char *lastName, int jerseyNumber, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->lastName, lastName);
    newNode->jerseyNumber = jerseyNumber;

    if (*head == NULL)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    if (pos == 1)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nInvalid position.\n");
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    system("cls");
}

void edit(struct Node **head, int new_jerseyNumber, int pos)
{
    struct Node *current = *head;

    for (int i = 1; i < pos && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    else
        printf("\nJersey(s) has been added to the list.\n");

    current->jerseyNumber = new_jerseyNumber;
    system("cls");
}

void delete(struct Node **head, int pos)
{
    struct Node *current = *head;

    if (*head == NULL)
    {
        printf("Jersey List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        *head = current->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(current);
        return;
    }

    for (int i = 1; i < pos && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    free(current);
    system("cls");
}

void display(struct Node **head)
{
    int i = 1;
    struct Node *current = *head;

    if (current == NULL)
    {
        printf("Jersey List is empty.\n");
        return;
    }

    printf("\nJersey List:\n");
    while (current != NULL)
    {
        printf("\n\t%d.\n\tName: %s\n\tNumber: %d\n", i, current->lastName, current->jerseyNumber);
        current = current->next;
        i++;
    }
}

void displayReverse(struct Node **head)
{
    int count = 0;
    struct Node *current = *head;

    if (current == NULL)
    {
        printf("Jersey List is empty.\n");
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
        count++;
    }

    printf("\nJersey List in Reverse:\n");
    int i = count + 1;
    struct Node *reverseCurrent = current;
    while (reverseCurrent != NULL)
    {
        printf("\n\t%d.\n\tName: %s\n\tNumber: %d\n", i, reverseCurrent->lastName, reverseCurrent->jerseyNumber);
        reverseCurrent = reverseCurrent->prev;
        i--;
    }
}