#ifndef DISPENSER_H
#define DISPENSER_H

typedef struct
{
    char nameOfItem[20];
    int numberOfItems;
    int cost;
} Dispenser;

int getCount(Dispenser dispenser);
int getProductCost(Dispenser dispenser);
int makeSale(Dispenser *dispenser, int moneyInserted);

#endif