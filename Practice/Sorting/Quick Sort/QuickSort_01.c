// 6 3 7 5 1 2 [4] (selects pivot [], always the last element)
//              |
//         3 1 [2] 4 6 7 [5]
// partition the array around the pivot (el < pivot = before, el > pivot = after)
//              |          |
//          1 2 3        5 7 [6]
//                            |
//                            6 7
//          1 2 3 4 5 6 7

// Time Complexity
// Best         Average       Worst
// Ω(n log(n))  θ(n log(n))   O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void quicksort(int arr[], int len);
void qs_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int arr[] = {4, 1, 5, 3, 0, 6, 10, 7, 8, 9, 2};
    int len = sizeof(arr) / sizeof(int);

    quicksort(arr, len);

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
    // optimized section
    srand(time(NULL));

    qs_recursion(arr, 0, len - 1);
}

void qs_recursion(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        qs_recursion(arr, low, pivot_index - 1);  // left hand portion
        qs_recursion(arr, pivot_index + 1, high); // right hand portion
    }
}

int partition(int arr[], int low, int high)
{
    //              j
    // 3 1 2 4 6 7 [5]
    //       i
    //
    // retrun 4

    // arr[high] can be inefficient in some cases
    // int pivot_value = arr[high];

    // optimized section
    int pivot_index = low + (rand() & (high - low)); // generating random number between low & high

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

    return i; // returns where the pivot is located
}