#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void quicksort(int arr[], int len);
void qs_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100;

    printf("\nRandom List:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\nList after each passes:\n");
    quicksort(arr, len);

    printf("\nSorted List:\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int arr[], int len)
{
    qs_recursion(arr, 0, len - 1);
}

void qs_recursion(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        qs_recursion(arr, low, pivot_index - 1);
        qs_recursion(arr, pivot_index + 1, high);
    }

    for (int i = 0; i < high + 1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot_index = low + (rand() % (high - low + 1));

    if (pivot_index != high)
        swap(&arr[pivot_index], &arr[high]);

    int pivot_value = arr[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot_value)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}
