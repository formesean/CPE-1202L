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
void display(struct Node *head, int i);

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
            system("cls");
            display(head, 1);
            printf("\nHow many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");   // O(1)
                gets(lastName);                           // O(n)
                printf("Enter player's jersey number: "); // O(1)
                scanf("%d", &jerseyNumber);               // O(1)
                fflush(stdin);                            // O(1)
                prepend(&head, lastName, jerseyNumber);   // O(1)
            }
            display(head, 1);
            break;
        case 2:
            system("cls");
            display(head, 1);
            printf("\nHow many Jersey do you want to create? ");
            scanf("%d", &num);
            fflush(stdin);

            for (int i = 0; i < num; i++)
            {
                printf("\nEnter player's last name: ");   // O(1)
                gets(lastName);                           // O(n)
                printf("Enter player's jersey number: "); // O(1)
                scanf("%d", &jerseyNumber);               // O(1)
                fflush(stdin);                            // O(1)
                append(&head, lastName, jerseyNumber);    // O(1)
            }
            display(head, 1);
            break;
        case 3:
            system("cls");
            display(head, 1);
            printf("\nEnter player's last name: ");      // O(1)
            gets(lastName);                              // O(n)
            printf("Enter player's jersey number: ");    // O(1)
            scanf("%d", &jerseyNumber);                  // O(1)
            printf("Enter the position to insert at: "); // O(1)
            scanf("%d", &pos);                           // O(1)
            insert(&head, lastName, jerseyNumber, pos);  // O(pos) or O(n)
            display(head, 1);
            break;
        case 4:
            system("cls");
            display(head, 1);
            printf("\nEnter the position of the player to edit: "); // O(1)
            scanf("%d", &pos);                                      // O(1)
            printf("Enter new jersey number: ");                    // O(1)
            scanf("%d", &jerseyNumber);                             // O(1)
            fflush(stdin);                                          // O(1)
            edit(&head, jerseyNumber, pos);                         // O(pos) or O(n)
            display(head, 1);
            break;
        case 5:
            system("cls");
            display(head, 1);
            printf("\nEnter the position to delete: "); // O(1)
            scanf("%d", &pos);                          // O(1)
            delete (&head, pos);                        // O(pos) or O(n)
            display(head, 1);
            break;
        case 6:
            system("cls");
            printf("\nExiting...\n");
            exit(1);
        default:
            system("cls");
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void prepend(struct Node **head, char *lastName, int jerseyNumber) // O(1)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // O(1)

    strcpy(newNode->lastName, lastName);  // O(n)
    newNode->jerseyNumber = jerseyNumber; // O(1)
    newNode->next = *head;                // O(1)
    *head = newNode;                      // O(1)
    system("cls");                        // O(1)
}

void append(struct Node **head, char *lastName, int jerseyNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // O(1)

    strcpy(newNode->lastName, lastName);  // O(n)
    newNode->jerseyNumber = jerseyNumber; // O(1)
    newNode->next = NULL;                 // O(1)

    if (*head == NULL) // O(1)
    {
        *head = newNode; // O(1)
        return;
    }

    // O(n) (line 148-155)
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode; // O(1)
    system("cls");        // O(1)
}

void insert(struct Node **head, char *lastName, int jerseyNumber, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // O(1)

    strcpy(newNode->lastName, lastName);  // O(n)
    newNode->jerseyNumber = jerseyNumber; // O(n)
    newNode->next = NULL;                 // O(1)

    // O(1) (line 166-171)
    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;        // O(1)
    for (int i = 0; i < pos - 2; i++) // O(n)
    {
        temp = temp->next; // O(1)
    }

    newNode->next = temp->next; // O(1)
    temp->next = newNode;       // O(1)
    system("cls");              // O(1)
}

void edit(struct Node **head, int new_jerseyNumber, int pos)
{
    struct Node *current = *head; // O(1)
    int i = 1;                    // O(1)

    while (current != NULL && i < pos) // O(n)
    {
        current = current->next; // O(1)
        i++;                     // O(1)
    }

    if (current == NULL) // O(1)
    {
        printf("Error: List is too short");
        return;
    }

    current->jerseyNumber = new_jerseyNumber; // O(1)
    system("cls");                            // O(1)
}

void delete(struct Node **head, int pos)
{
    struct Node *newNode = *head; // O(1)

    if (pos == 1) // O(1)
    {
        *head = newNode->next; // O(1)
        free(newNode);         // O(1)
        return;
    }

    for (int i = 0; i < pos - 2; i++) // O(n)
    {
        newNode = newNode->next; // O(1)
    }

    struct Node *temp = newNode->next; // O(1)
    newNode->next = temp->next;        // O(1)
    free(temp);                        // O(1)
    system("cls");                     // O(1)
}

void display(struct Node *head, int i)
{
    if (head == NULL) // O(1)
    {
        printf("\nJersey List:\n"); // O(1)
        return;
    }

    printf("\n\t%d.\n\tName: %s\n\tNumber: %d\n", i, head->lastName, head->jerseyNumber); // O(1)
    display(head->next, i + 1);                                                           // O(1)
}