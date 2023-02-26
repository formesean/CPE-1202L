// Time Complexity
// Best         Average       Worst
// Ω(n)         θ(n^2)        O(n^2)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {4, 1, 5, 3, 6, 10, 7, 8, 9, 2};
    int length = sizeof(arr) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}