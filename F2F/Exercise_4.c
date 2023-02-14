#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 20
#define MAX_LINE 2048

typedef struct
{
    char firstName[20];
    char lastName[20];
} FormulaOneDriver;

void addDriverDetails(FormulaOneDriver *driver, int index);
void printDriverDetails(FormulaOneDriver *driver, int index);
void editDriverDetails(FormulaOneDriver *drivers, int numDrivers, int index);
void removeDriver(FormulaOneDriver *drivers, int index);

int main()
{
    int choice, index, num;
    char names[50];
    char *token;

    do
    {
        int numDrivers = 0;
        FILE *db;
        db = fopen("db.txt", "r");
        if (db == NULL)
        {
            printf("Cannot open file.");
            return 1;
        }

        FormulaOneDriver *drivers = (FormulaOneDriver *)malloc(MAX_OBJECTS * sizeof(FormulaOneDriver));
        if (drivers == NULL)
        {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }

        printf("Drivers in the Database:\n\n");
        while (fgets(names, sizeof(names), db) != NULL)
        {
            token = strtok(names, ";");
            printf("\tDriver %d: %s ", numDrivers + 1, token);

            token = strtok(NULL, ";");
            printf("%s\n", token);
            numDrivers++;
        }

        fclose(db);

        printf("\n\nChoose an option:\n");
        printf("1 - Add Driver\n");
        printf("2 - Edit Driver\n");
        printf("3 - Remove Driver\n");
        printf("4 - Quit\n\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            printf("Enter the number of drivers to add: ");
            scanf("%d", &num);
            fflush(stdin);

            if (numDrivers + num > MAX_OBJECTS)
            {
                printf("Error: Maximum number of drivers exceeded.\n");
            }
            else
            {
                for (int i = numDrivers; i < numDrivers + num; i++)
                {
                    addDriverDetails(&drivers[i], i);
                }
            }
            break;
        case 2:
            if (numDrivers == 0)
            {
                printf("Error: No drivers to edit.\n");
            }
            else
            {
                printf("Enter the number of the driver to edit: ");
                scanf("%d", &index);
                fflush(stdin);
                editDriverDetails(&drivers[index - 1], numDrivers, index - 1);
            }
            break;
        case 3:
            if (numDrivers == 0)
            {
                printf("Error: No drivers to remove.\n");
            }
            else
            {
                printf("Enter the number of the driver to remove: ");
                scanf("%d", &index);
                fflush(stdin);
                removeDriver(drivers, index);
            }
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid option. Try again.\n");
        }
        system("cls");
        free(drivers);
    } while (choice != 4);

    return 0;
}

void addDriverDetails(FormulaOneDriver *driver, int index)
{
    printf("\nEnter the name of Driver %d\n", index + 1);
    printf("First Name: ");
    scanf("%s", driver->firstName);
    fflush(stdin);
    printf("Last Name: ");
    scanf("%s", driver->lastName);
    fflush(stdin);

    FILE *db;
    db = fopen("db.txt", "r");
    if (db == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, db) != NULL)
    {
        char *first = strtok(line, ";");
        char *last = strtok(NULL, ";");
        if (strcmp(first, driver->firstName) == 0 && strcmp(last, driver->lastName) == 0)
        {
            fclose(db);
            return;
        }
    }

    fclose(db);

    db = fopen("db.txt", "a");
    if (db == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    fprintf(db, "%s;%s\n", driver->firstName, driver->lastName);
    fclose(db);
}

void printDriverDetails(FormulaOneDriver *driver, int index)
{
    printf("\tDriver %d: %s %s\n", index + 1, driver->firstName, driver->lastName);
}

void editDriverDetails(FormulaOneDriver *drivers, int numDrivers, int index)
{
    printf("\nEnter the new details for this driver:\n");

    printf("First Name: ");
    scanf("%s", drivers[index].firstName);
    fflush(stdin);
    printf("Last Name: ");
    scanf("%s", drivers[index].lastName);
    fflush(stdin);

    FILE *db, *temp;
    db = fopen("db.txt", "r");
    temp = fopen("temp.txt", "w");
    if (db == NULL || temp == NULL)
    {
        printf("Cannot open file.");
        return;
    }

    char buffer[MAX_LINE];
    int line = 0;
    while (fgets(buffer, MAX_LINE, db))
    {
        if (line == index)
            fprintf(temp, "%s;%s\n", drivers[index].firstName, drivers[index].lastName);
        else
            fputs(buffer, temp);

        line++;
    }

    fclose(db);
    fclose(temp);

    remove("db.txt");
    rename("temp.txt", "db.txt");

    printf("\nDriver database has been updated.\n");
}

void removeDriver(FormulaOneDriver *drivers, int index)
{
    FILE *db, *temp;
    db = fopen("db.txt", "r");
    temp = fopen("temp.txt", "w");
    if (db == NULL || temp == NULL)
    {
        printf("Cannot open file.");
        return;
    }

    char buffer[MAX_LINE];
    int line = 0;

    while (fgets(buffer, MAX_LINE, db))
    {
        line++;

        if (line != index)
            fputs(buffer, temp);
    }

    fclose(db);
    fclose(temp);

    remove("db.txt");
    rename("temp.txt", "db.txt");

    printf("Driver database has been updated.\n");
}
