#include <stdio.h>
#include <stdlib.h>

#define min_SIZE 100

// Declare the minHeap structure
typedef struct minHeap {
    int* data;
    int size;
    int capacity;
} minHeap;

minHeap* createminHeap(int capacity) {
    minHeap* heap = (minHeap*)malloc(sizeof(minHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->data = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements in the minHeap
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


// minHeapify the given index in the minHeap
void minHeapify(minHeap* minHeap, int index) {

    //set the smallest as current index
    int smallest = index;

    //get left child
    int left = getLeftChild(index);

    //get right child
    int right = getRightChild(index);

    //Find the smallest element among current index and its left and right child.
    if (left < minHeap->size && minHeap->data[left] < minHeap->data[smallest]) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->data[right] < minHeap->data[smallest]) {
        smallest = right;
    }

    // Swap the value of current index with the index where the smallest element is located
    if (smallest != index) {
        swap(&minHeap->data[index], &minHeap->data[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a new element into the minHeap
void insert(minHeap* minHeap, int value) {
    if (minHeap == NULL) return;

    if (minHeap->size == min_SIZE) {
        printf("minHeap is at maximum capacity.\n");
        return;
    }

    minHeap->data[minHeap->size] = value;
    int current = minHeap->size;
    int parent = getParent(current);

    while (current != 0 && minHeap->data[parent] > minHeap->data[current]) {
        swap(&minHeap->data[current], &minHeap->data[parent]);
        current = parent;
        parent = getParent(current);
    }

    minHeap->size++;
}

// Function to remove the minimum element from the minHeap
int removeMin(minHeap* minHeap) {
    if (minHeap == NULL) return -1;

    //Empty minHeap
    if (minHeap->size == 0) {
        printf("minHeap is empty, cannot remove element.\n");
        return -1;
    }

    //Store the first element(min) to remove
    int min = minHeap->data[0];

    //Set the rightmost element as new node.
    minHeap->data[0] = minHeap->data[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return min;
}

// Function to remove an element with a specific value from the minHeap
void removeValue(minHeap* minHeap, int value) {
    if (minHeap == NULL) return;

    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->data[i] == value) {
            break;
        }
    }

    if (i == minHeap->size) {
        printf("Value not found in minHeap.\n");
        return;
    }

    minHeap->data[i] = minHeap->data[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, i);
}


void freeminHeap(minHeap* minHeap){
    if(minHeap != NULL) {
        if(minHeap->data != NULL) {
            free(minHeap->data);
        }
        free(minHeap);
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    minHeap* minHeap = createminHeap(1000);

    // Insert some elements into the minHeap
    insert(minHeap, 10);
    insert(minHeap, 20);
    insert(minHeap, 15);
    insert(minHeap, 30);
    insert(minHeap, 5);
    insert(minHeap, 60);

    printArray(minHeap->data, minHeap->size);

    // Test removeMin and min_minHeapify
    printf("min value removed: %d\n", removeMin(minHeap));
    printArray(minHeap->data, minHeap->size);

    insert(minHeap, 80);
    printArray(minHeap->data, minHeap->size);
    printf("min value removed: %d\n", removeMin(minHeap));
    printArray(minHeap->data, minHeap->size);

    // // Test removeValue and min_minHeapify
    // removeValue(&minHeap, 15);

    // // Test delete and min_Heapify
    // delete(&minHeap, 1);

    free(minHeap);
    return 0;
}
