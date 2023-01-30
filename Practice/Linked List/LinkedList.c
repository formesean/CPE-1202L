#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertStart(int data, int x);
void insertEnd(int data, int x);
void delete(int y);
void reverse();
void display();

int main()
{
    return 0;
}