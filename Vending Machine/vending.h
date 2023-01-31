#ifndef VENDING_H
#define VENDING_H

struct Dispenser
{
    char nameOfItem[20];
    int numberOfItems;
    int price;
};

struct CashRegister
{
    int cashOnHand;
    int currentBalance;
};

void showSelection(const struct Dispenser dispensers[], int size);
void sellProduct(const struct Dispenser dispensers[], int size, struct CashRegister *cashRegister);

#endif