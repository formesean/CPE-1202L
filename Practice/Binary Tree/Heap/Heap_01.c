#include <stdio.h>

#define MAX_HEAP_SIZE 1000

int heap[MAX_HEAP_SIZE];
int heap_size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int i)
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < heap_size && heap[left_child] > heap[largest])
    {
        largest = left_child;
    }

    if (right_child < heap_size && heap[right_child] > heap[largest])
    {
        largest = right_child;
    }

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        max_heapify(largest);
    }
}

void build_max_heap(int *array, int array_size)
{
    heap_size = array_size;

    for (int i = array_size / 2; i >= 0; i--)
    {
        max_heapify(i);
    }
}

void heap_sort(int *array, int array_size)
{
    build_max_heap(array, array_size);

    for (int i = array_size - 1; i >= 1; i--)
    {
        swap(&array[0], &array[i]);
        heap_size--;
        max_heapify(0);
    }
}

void insert(int value)
{
    if (heap_size >= MAX_HEAP_SIZE)
    {
        printf("Heap is full. Cannot insert any more elements.\n");
        return;
    }

    heap[heap_size] = value;
    int current_index = heap_size;

    while (current_index > 0 && heap[(current_index - 1) / 2] < heap[current_index])
    {
        swap(&heap[(current_index - 1) / 2], &heap[current_index]);
        current_index = (current_index - 1) / 2;
    }

    heap_size++;
}

int extract_max()
{
    if (heap_size <= 0)
    {
        printf("Heap is empty. Cannot extract any element.\n");
        return -1;
    }

    int max_value = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    max_heapify(0);

    return max_value;
}

void print_heap()
{
    printf("Heap: ");
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {12, 3, 17, 9, 8, 7};
    int array_size = sizeof(array) / sizeof(int);

    build_max_heap(array, array_size);
    print_heap();

    insert(15);
    print_heap();

    int max_value = extract_max();
    printf("Max value extracted: %d\n", max_value);
    print_heap();

    heap_sort(array, array_size);
    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
