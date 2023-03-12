#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int len)
{
    int gap, temp;
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i += 1)
        {
            temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {4, 1, 5, 3, 0, 6, 10, 7, 8, 9, 2};
    int len = sizeof(arr) / sizeof(int);

    shellSort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}