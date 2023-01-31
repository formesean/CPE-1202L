#include <stdio.h>
#include <stdlib.h>
#include "vending.h"

void showSelection(const struct Dispenser dispensers[], int size)
{
    printf("Items available in the vending machine:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d %s\n", i + 1, dispensers[i].nameOfItem);
    }
}

void sellProduct(const struct Dispenser dispensers[], int size, struct CashRegister *cashRegister)
{
    int choice;

    showSelection(dispensers, size);

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > size)
    {
        printf("Invalid choice.\n");
        return;
    }

    int selectedDispenserIndex = choice - 1;
    struct Dispenser selectedDispenser = dispensers[selectedDispenserIndex];

    if (selectedDispenser.numberOfItems == 0)
    {
        printf("%s is sold out.\n", selectedDispenser.nameOfItem);
    }

    int productCost = selectedDispenser.price;
    printf("%s costs %d.\n", selectedDispenser.nameOfItem, productCost);

    int amountReceived;
    printf("Enter amount: ");
    scanf("%d", &amountReceived);

    if (amountReceived < productCost)
    {
        printf("Insufficient amount.\n");
        return;
    }

    selectedDispenser.numberOfItems--;
    cashRegister->cashOnHand = cashRegister->cashOnHand + productCost;
    cashRegister->currentBalance = amountReceived - productCost;

    printf("Here's your %s.\n Enjoy!\n", selectedDispenser.nameOfItem);
    printf("Change: %d", cashRegister->currentBalance);
}