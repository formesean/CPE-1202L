#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {4, 1, 5, 3, 6, 10, 7, 8, 9, 2};
    int length = sizeof(arr) / sizeof(int);

    for (int i = 0; i < length - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    return 0;
}