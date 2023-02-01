#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECTS 20

typedef struct {
    char firstName[20];
    char lastName[20];
} FormulaOneDrivers;

void getDriverDetails(FormulaOneDrivers *driver, int index);
void printDriverDetails(FormulaOneDrivers *driver, int index);

int main()
{
    int numDrivers;
    int i = 0;
    do {
        printf("Enter the number of Drivers (maximum of %d): ", MAX_OBJECTS);
        scanf("%d", &numDrivers);

        if (numDrivers > MAX_OBJECTS) 
            printf("Error: Maximum number of drivers exceeded.\n\n");
    } while (numDrivers > MAX_OBJECTS);
    
    FormulaOneDrivers drivers[numDrivers];
    
    for (i = 0; i < numDrivers ; i++) {
        getDriverDetails(&drivers[i], i);
    }
    
    printf("\nDriver Name List:\n");
    for (i = 0; i < numDrivers; i++) {
        printDriverDetails(&drivers[i], i);
    }

    return 0;
}

void getDriverDetails(FormulaOneDrivers *driver, int index) {
    printf("\nEnter the name of Driver %d\n", index + 1);
    printf("First Name: ");
    scanf("%s", driver->firstName);
    printf("Last Name: ");
    scanf("%s", driver->lastName);
}

void printDriverDetails(FormulaOneDrivers *driver, int index) {
    printf("\nDriver %d: %s %s\n", index + 1, driver->firstName, driver->lastName);
}
