#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {4, 1, 5, 3, 6, 10, 7, 8, 9, 2};
    int length = 10;

    sort(arr, length);

    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    return 0;
}