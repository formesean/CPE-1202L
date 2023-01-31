#include <stdio.h>
#include <stdlib.h>
#include "cashregister.h"

double currentBalance(double cashOnHand, double cost)
{
    return cashOnHand - cost;
}

void acceptMoney(double *cashOnHand, double cost)
{
    double balance = *cashOnHand - cost;
    int tries = 2;
    while (balance < 0 && tries > 0)
    {
        printf("Insufficient funds, please insert additional amount: ");
        scanf("%lf", cashOnHand);
        balance = *cashOnHand - cost;
        tries--;
    }
    if (balance >= 0)
    {
        printf("Transaction successful!\n");
        *cashOnHand = balance;
    }
    else
    {
        printf("Transaction failed, returning money...\n");
    }
}
