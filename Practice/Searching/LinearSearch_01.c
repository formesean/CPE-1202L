// Time Complexity
// Best         Average       Worst
// O(1)         O(n)          O(n)

#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int len, int searchData)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == searchData)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {15, 5, 20, 35, 2, 42, 67, 17};
    int len = sizeof(arr) / sizeof(int);
    int searchData;

    printf("\nEnter data to search: ");
    scanf("%d", &searchData);
    fflush(stdin);

    int result = search(arr, len, searchData);

    if (result == -1)
        printf("Data not Found.");
    else
        printf("Data found at index %d", result);

    return 0;
}