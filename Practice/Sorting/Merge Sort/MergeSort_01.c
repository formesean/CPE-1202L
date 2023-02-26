// Time Complexity
// Best         Average       Worst
// Ω(n log(n))  θ(n log(n))   O(n log(n))

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int length);
void sort_recursion(int arr[], int left, int right);
void merge_sorted_arrays(int arr[], int l, int m, int r);

int main()
{
    int arr[] = {4, 1, 5, 3, 0, 6, 10, 7, 8, 9, 2};
    int length = sizeof(arr) / sizeof(int);

    merge_sort(arr, length);

    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void merge_sort(int arr[], int length)
{
    sort_recursion(arr, 0, length - 1);
}

void sort_recursion(int arr[], int left, int right)
{
    if (left < right) // continue to divide unsorted array into smaller portion
    {
        int middle = left + (right - left) / 2;

        sort_recursion(arr, left, middle);      // indexes defining left portion
        sort_recursion(arr, middle + 1, right); // indexes defining right portion

        merge_sorted_arrays(arr, left, middle, right);
    }
}

void merge_sorted_arrays(int arr[], int l, int m, int r)
{
    // l = starting index of the left portion
    // m = middle index
    // l = last index of the right portion

    int l_len = m - l + 1; // length of the left portion
    int r_len = r - m;     // length of the right portion

    int temp_l[l_len];
    int temp_r[r_len];

    int i, j, k;

    for (int i = 0; i < l_len; i++)
        temp_l[i] = arr[l + i];

    for (int i = 0; i < r_len; i++)
        temp_r[i] = arr[m + 1 + i];

    // k = keeps track of our place on the array
    // i = keeps index into temp_l
    // j = keeps index into temp_r
    //
    //            i
    // temp_l: 4, 9, 12
    //
    //            j
    // temp_r: 5, 8, 14
    //
    //               k
    //      a: 4, 5,
    //
    // if i !< l_len then its the end and not copy from temp_l, only at temp_r.
    // if j >= r_len then its the end.

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < l_len) && (j >= r_len || temp_l[i] <= temp_r[j]))
        {
            arr[k] = temp_l[i];
            i++;
        }
        else
        {
            arr[k] = temp_r[j];
            j++;
        }
    }
}