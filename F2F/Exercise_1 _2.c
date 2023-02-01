#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECTS 20

struct formulaOneDrivers {
    char firstName[20];
    char lastName[20];
};

int main()
{
    int numDrivers;
    do {
        printf("Enter the number of Drivers (maximum of %d): ", MAX_OBJECTS);
        scanf("%d", &numDrivers);

        if (numDrivers > MAX_OBJECTS) 
            printf("Error: Maximum number of drivers exceeded.\n\n");
    } while (numDrivers > MAX_OBJECTS);
    
    struct formulaOneDrivers drivers[numDrivers];
    
    for (int i = 0; i < numDrivers ; i++) {
        printf("\nEnter the name of Driver %d\n", i+1);
        
        printf("First Name: ");
        scanf("%s", drivers[i].firstName);
        printf("Last Name: ");
        scanf("%s", drivers[i].lastName);
    }
    
    printf("Driver Name List:\n");
    for (int i = 0; i < numDrivers; i++) {
        printf("\nDriver %d: ", i+1);
        printf("%s %s\n", drivers[i].firstName, drivers[i].lastName);
    }

    return 0;
}



