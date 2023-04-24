#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "maxHeap.h" 

//Test the max heap implementation using Array

int main() {
    int test_array[] = {15, 5, 3, 1, 8, 7, 2, 10};
    int array_size = sizeof(test_array) / sizeof(test_array[0]);

    printf("Original array:\n");
    printArray(test_array, array_size);

    // Test heap sort
    heapSort(test_array, array_size);
    printf("Sorted array using heap sort:\n");
    printArray(test_array, array_size);

    // Test max heap operations
    int capacity = 10;
    maxHeap* heap = createMaxHeap(capacity);

    printf("Inserting elements into the max heap:\n");
    for (int i = 0; i < array_size; i++) {
        insert(heap, test_array[i]);
    }
    printArray(heap->data, heap->size);

    printf("Removing the maximum element from the max heap:\n");
    int max = removeMax(heap);
    printf("Max element removed: %d\n", max);
    printArray(heap->data, heap->size);

    printf("Inserting 20 into the max heap:\n");
    insert(heap, 20);
    printArray(heap->data, heap->size);

    printf("Removing the minimum element from the max heap:\n");
    int min = removeMin(heap);
    printf("Min element removed: %d\n", min);

    printf("Removing the element 8 from the max heap:\n");
    removeValue(heap, 8);
    printArray(heap->data, heap->size);

    freeMaxHeap(heap);
    
    return 0;
}
