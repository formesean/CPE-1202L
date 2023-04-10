// Array implementation of Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int data, int len, int arr[])
{
    if (rear == len - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
    }
    arr[rear] = data;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display(int arr[])
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

int main()
{
    int arr[MAX_SIZE];
    int len = sizeof(arr) / sizeof(arr[0]);

    enqueue(1, len, arr);
    enqueue(2, len, arr);
    enqueue(3, len, arr);
    enqueue(4, len, arr);

    display(arr);

    dequeue();

    display(arr);

    return 0;
}