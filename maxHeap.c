#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maxHeap.h"

#define MAX_SIZE 500000000


// Create and malloc memory for maxheap
maxHeap* createMaxHeap(int capacity) {
    maxHeap* heap = (maxHeap*)malloc(sizeof(maxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->data = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements in the maxHeap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getParent(int i){
    return (i - 1) / 2;
}

int getLeftChild(int i){
    return 2 * i + 1;
}

int getRightChild(int i){
    return 2 * i + 2;
}


// maxHeapify the given index in the maxHeap
void maxHeapify(maxHeap* maxHeap, int index) {

    //set the largest as current index
    int largest = index;

    //get left child
    int left = getLeftChild(index);

    //get right child
    int right = getRightChild(index);

    //Find the largest element among current index and its left and right child.
    if (left < maxHeap->size && maxHeap->data[left] > maxHeap->data[largest]) {
        largest = left;
    }
    if (right < maxHeap->size && maxHeap->data[right] > maxHeap->data[largest]) {
        largest = right;
    }

    // Swap the value of current index with the index where the largest element is located
    if (largest != index) {
        swap(&maxHeap->data[index], &maxHeap->data[largest]);
        maxHeapify(maxHeap, largest);
    }
}

// Insert a new element into the maxHeap
void insert(maxHeap* maxHeap, int value) {
    if (maxHeap == NULL) return;

    if (maxHeap->size == MAX_SIZE) {
        printf("maxHeap is at maximum capacity.\n");
        return;
    }

    //First insert the new value at the first vacancy of the heap
    maxHeap->data[maxHeap->size] = value;
    int current = maxHeap->size;
    int parent = getParent(current);

    //Check whether the added value is bigger than its parent
    //If yes, swap with the parent
    //Iterating thes movement until its parent is larger or when reaching the root
    while (current != 0 && maxHeap->data[parent] < maxHeap->data[current]) {
        swap(&maxHeap->data[current], &maxHeap->data[parent]);
        current = parent;
        parent = getParent(current);
    }

    maxHeap->size++;
}

// Remove the maximum element from the maxHeap
int removeMax(maxHeap* maxHeap) {
    if (maxHeap == NULL) return -1;

    //Empty maxHeap
    if (maxHeap->size == 0) {
        printf("maxHeap is empty, cannot remove element.\n");
        return -1;
    }

    //Store the first element(max) to remove
    int max = maxHeap->data[0];

    //Set the rightmost element as new node.
    maxHeap->data[0] = maxHeap->data[maxHeap->size - 1];
    maxHeap->size--;

    maxHeapify(maxHeap, 0);

    return max;
}

// Remove the minimum element from the maxHeap

int removeMin(maxHeap* maxHeap) {
    if (maxHeap == NULL) return -1;

    if (maxHeap->size == 0) {
        printf("maxHeap is empty, cannot remove element.\n");
        return -1;
    }

    int min = maxHeap->data[maxHeap->size - 1];
    maxHeap->data[maxHeap->size - 1] = maxHeap->data[0];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);

    return min;
}

// Remove an element with a specific value from the maxHeap
void removeValue(maxHeap* maxHeap, int value) {
    if (maxHeap == NULL) return;

    int i;
    for (i = 0; i < maxHeap->size; i++) {
        if (maxHeap->data[i] == value) {
            break;
        }
    }

    if (i == maxHeap->size) {
        printf("Value not found in maxHeap.\n");
        return;
    }

    maxHeap->data[i] = maxHeap->data[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, i);
}


void freeMaxHeap(maxHeap* maxHeap){
    if(maxHeap != NULL) {
        if(maxHeap->data != NULL) {
            free(maxHeap->data);
        }
        free(maxHeap);
    }
}

void heapSort(int arr[], int n) {
    maxHeap* heap = createMaxHeap(n);

    // Insert all elements into the max heap
    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }

    // Remove the maximum element from the heap and put it at the end of the array
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = removeMax(heap);
    }

    freeMaxHeap(heap);
}


void printArray(int arr[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

