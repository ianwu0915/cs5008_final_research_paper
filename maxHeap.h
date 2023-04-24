// max_heap.h
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct maxHeap {
    int* data;
    int size;
    int capacity;
} maxHeap;

maxHeap* createMaxHeap(int capacity);
void swap(int* a, int* b);
int getParent(int i);
int getLeftChild(int i);
int getRightChild(int i);
void maxHeapify(maxHeap* maxHeap, int index);
void insert(maxHeap* maxHeap, int value);
int removeMax(maxHeap* maxHeap);
int removeMin(maxHeap* maxHeap);
void removeValue(maxHeap* maxHeap, int value);
void freeMaxHeap(maxHeap* maxHeap);
void heapSort(int arr[], int n);
void printArray(int arr[], int size);
