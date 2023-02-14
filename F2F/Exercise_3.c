#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 20

typedef struct
{
    char firstName[20];
    char lastName[20];
} FormulaOneDriver;

void getDriverDetails(FormulaOneDriver *driver, int index);
void printDriverDetails(FormulaOneDriver *driver, int index);

int main()
{
    int numDrivers;
    int i = 0;
    char names[50];
    char *token;

    do
    {
        FILE *db;
        db = fopen("db.txt", "a+");
        if (db == NULL)
        {
            printf("Cannot open file.");
            return 1;
        }

        printf("Drivers of the Database:\n\n");
        while (fgets(names, sizeof(names), db) != NULL)
        {
            token = strtok(names, ";");
            printf("\tDriver %d: %s ", i + 1, token);

            token = strtok(NULL, ";");
            printf("%s\n", token);
            i++;
        }

        printf("Enter the number of Drivers (maximum of %d): ", MAX_OBJECTS);
        scanf("%d", &numDrivers);
        fflush(stdin);

        if (numDrivers > MAX_OBJECTS)
        {
            printf("Error: Maximum number of drivers exceeded.\n\n");
            continue;
        }

        FormulaOneDriver *drivers = (FormulaOneDriver *)malloc(numDrivers * sizeof(FormulaOneDriver));
        if (drivers == NULL)
        {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }

        for (i = 0; i < numDrivers; i++)
        {
            getDriverDetails(&drivers[i], i);
        }

        printf("\nDriver Name List:\n");
        for (i = 0; i < numDrivers; i++)
        {
            printDriverDetails(&drivers[i], i);
        }

        for (i = 0; i < numDrivers; i++)
        {
            fprintf(db, "%s;%s\n", drivers[i].firstName, drivers[i].lastName);
        }

        fclose(db);

        free(drivers);
        return 0;
    } while (numDrivers > MAX_OBJECTS);
}

void getDriverDetails(FormulaOneDriver *driver, int index)
{
    printf("\nEnter the name of Driver %d\n", index + 1);
    printf("First Name: ");
    scanf("%s", driver->firstName);
    fflush(stdin);
    printf("Last Name: ");
    scanf("%s", driver->lastName);
    fflush(stdin);
}

void printDriverDetails(FormulaOneDriver *driver, int index)
{
    printf("Driver %d: %s %s\n", index + 1, driver->firstName, driver->lastName);
}
