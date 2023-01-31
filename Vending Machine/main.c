#include <stdio.h>
#include <stdlib.h>
#include "vending.h"
#include "dispenser.h"
#include "cashregister.h"

int main(void)
{
    float money = 0;
    int choice = 0;
    float change = 0;
    loadDispenser();

    while (choice != -1)
    {
        showSelection(dispenser);
        choice = makeSelection();
        if (choice == -1)
        {
            break;
        }
        money = getCost(dispenser, choice);
        change = sellProduct(dispenser, money, choice);
        updateDispenser(choice);
        saveDispenser();
    }

    return 0;
}