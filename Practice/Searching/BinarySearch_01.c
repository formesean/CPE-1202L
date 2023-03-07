// Time Complexity
// Best         Average       Worst
// O(1)         O(log n)      O(log n)

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int left, int right);

int main()
{
    int unsorted_arr[] = {4, 1, 5, 3, 0, 6, 10, 7, 8, 9, 2};
    int sorted_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len_unsorted = sizeof(unsorted_arr) / sizeof(int);
    int len_sorted = sizeof(sorted_arr) / sizeof(int);

    int index = binarySearch(sorted_arr, 6, 0, 10);

    printf("Index: %d", index);

    return 0;
}

int binarySearch(int arr[], int target, int left, int right)
{
    int mid = left + (right - left) / 2;

    if (left > right)
        return -1;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        binarySearch(arr, target, left, mid - 1);
    else
        binarySearch(arr, target, mid + 1, right);
}