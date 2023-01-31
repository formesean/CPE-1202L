#include <stdio.h>
#include <stdlib.h>
#include "dispenser.h"

int getCount(Dispenser dispenser)
{
    return dispenser.numberOfItems;
}

int getProductCost(Dispenser dispenser)
{
    return dispenser.cost;
}

int makeSale(Dispenser *dispenser, int moneyInserted)
{
    int change = 0;
    if (dispenser->numberOfItems > 0)
    {
        if (moneyInserted >= dispenser->cost)
        {
            dispenser->numberOfItems--;
            change = moneyInserted - dispenser->cost;
        }
        else
        {
            printf("Error: Not enough money inserted. Please insert additional %d.\n", dispenser->cost - moneyInserted);
        }
    }
    else
    {
        printf("Error: This product is sold out.\n");
    }
    return change;
}
