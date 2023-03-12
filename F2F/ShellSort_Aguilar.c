#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

            for (int k = 0; k < len; k++)
                printf("%d ", arr[k]);
            printf("\n");
        }
    }
}

int main()
{
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("\nRandom list: ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\nList after each passes:\n");
    shellSort(arr, len);

    printf("\nSorted list: ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
