#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "maxHeap.h" 
#define MAX_SIZE 500000

int main() {
    int* arr = malloc(MAX_SIZE * sizeof(int));
    maxHeap* maxHeap = createMaxHeap(MAX_SIZE);

    srand(time(NULL));

    // Insert random elements into the max heap and the array
    for (int i = 0; i < MAX_SIZE; i++) {
        int value = rand() % MAX_SIZE;
        // insert(maxHeap, value);
        arr[i] = value;
    }

    // Heap sort test
    // printf("Before heap sort: ");
    // printArray(arr, MAX_SIZE);

    clock_t start1 = clock();
    heapSort(arr, MAX_SIZE);
    clock_t end1 = clock();

    // printf("After heap sort: ");
    // printArray(arr, MAX_SIZE);
    printf("Heap sort time: %f seconds\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    // Time how long it takes to insert all the elements into the max heap
    clock_t start = clock();
    for (int i = 0; i < MAX_SIZE; i++) {
        insert(maxHeap, arr[i]);
    }
    clock_t end = clock();
    printf("Insertion time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Time how long it takes to remove the maximum element MAX_SIZE times
    start = clock();
    for (int i = 0; i < MAX_SIZE; i++) {
        removeMax(maxHeap);
    }
    end = clock();
    printf("Remove max time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    freeMaxHeap(maxHeap);

    return 0;
}