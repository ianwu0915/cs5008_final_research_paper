# Report on Max Heap Data Structure
Semester: 2023 Spring

Name: Hsinyen Wu

Github account name: ianwu0915

Link: 

## Introduction
---

Heap is a data structure that is used to represent a complete binary tree, where each node satisfies the heap property. The heap property is defined differently for max heaps and min heaps, but the general idea is that the value of each node is either greater than or equal to (max heap) or less than or equal to (min heap) the values of its children.

### MaxHeap  
    
As array:

    [50, 30, 20, 15, 10, 8, 5]

As complete binary tree:

             50                        
           /    \
         30      20
        /  \    /  \         
      15   10  8    5


### MinHeap  

As array:

    [1, 3 , 2, 7, 4, 5, 8]

As complete binary tree:

             1
           /   \
         3      2
        /  \   /  \
      7    4  5    9
  

This data structure was first introduced by J.W.J. Williams in 1964, as a way to efficiently sort large amounts of data on a computer. Heapsort, which is based on the heap data structure, was one of the fastest sorting algorithms at the time. One of its widely known application is to implement priority queue, a data structure
that enables efficient insertion and removal of elements based on their priority.

In this report, we will focus on discussing the implementation of a MaxHeap, and analyze its time complexity for various operations. We will run an empirical test to validate its time complexity. We will also discuss the advantages, disadvantages, and applications of heap data structure.

## Analysis of Algorithm/Datastructure
---

The theoretical time complexity of various operations of a MaxHeap data structure is shown below:

| Operation | Average | Best | Worst |
| --- | --- | --- | --- |
| Insert | O( $log{_2}{n}$ ) | O(1) | O( $log{_2}{n}$ ) |
| Delete | O( $log{_2}{n}$ ) | O($log(1)$) | O( $log{_2}{n}$ )  |
| Search | O( $log{_2}{n}$ )| O(1) | O($n$) |

### Insert

During insertion, we first add the element to the very end of the heap and check if the added value is larger than its parent. If it is, we shift the element upwards until the heap is properly structured.

* The best case of insertion would occur when the added value is smaller than its parent, so we don't have to move the element upwards. 

* Worst case occurs if we need to shift the inserted value all the way up to the root, which means that the added value is the biggest in the heap. Therefore we will have to shift the element upwards the levels of the heap, which are $log{_2}{n}$ levels.

* The average time complexity will thereby be the average of 1, 2, 3,... $log{_2}{n}$, which would be $log{_2}{n}$ after calculation.
&emsp;

### RemoveMAX

In MaxHeap, deletion is done by first removing the root elemtent and having the last element replace the root element. Then we check and shift "downward" the root element until the heap is properly structured.

* Best case occur when there is only one element in the heap. When we remove the element, the heap then becomes empty, so we do not have to rearrange the heap. Therefore, the best case is O(1).

* Worst case occur when there is more than one element in the heap. Therefore, we would have to downshift the element that replaces the root element at maximum $log{_2}{n}$ levels. The worst case is thereby O($log{_2}{n}$).

* The average time complexity will therefore be the average of 1, 2, 3,... $log{_2}{n}$, which would be O($log{_2}{n}$).

### Heap Sort

* Heap sort is done by using removeMax function to remove all elements and store the removed elements in an array. 
* Since we always remove the max value at each time, we will eventually get a sorted array.The sorting process will involve removing all elements, so the time complexity is O(${n}log{_2}{n}$)


### Space Complexity

* The space complexity of a MaxHeap is O(n), where n is the number of elements in the heap. This is because the heap can be represented using an array of size n.  
&emsp;


## Implementation
---
The code for the MaxHeap data structure is generally implemented in C using array.

Although it is possible to implement heap using linked list, it would be much more challenging. Implementing using an array can be easily done by swapping elements within the array. We can also simply print out the array to present the data of the heap in the right order.

Contraily, when using linked list, we would have to maintatin property of heap and linked list simultaneously, which is very complex. For instance, to print out value in a proper heap order, we also have to apply Queue to implement bread-first-search.

I have tried using linked list to implement MaxHeap but failed due to its complexity. 
The incomplete implementaion of max heap using linked list is written in the following file: 

'[heap_linked_list.c](heap_linked_list.c)'

Implementations of MaxHeap and MinHeap using Array are in the following file.

'[maxHeap.c](maxHeap.c)'

'[minHeap.c](minHeap_array.c)'

The test of our MaxHeap implementation is written in the file below:

'[test.c](test.c)'

### Functions in MaxHeap implementation

- `createMaxHeap(int capacity)`: This function creates and allocates memory for a new max heap with the given capacity.

- `swap(int* a, int* b)`: This function swaps the values of two integers.

- `getParent(int i)`: This function returns the index of the parent node of the given index in the max heap.

- `getLeftChild(int i)`: This function returns the index of the left child node of the given index in the max heap.

- `getRightChild(int i)`: This function returns the index of the right child node of the given index in the max heap.

- `maxHeapify(maxHeap* maxHeap, int index)`: This function recursively max heapifies the max heap starting from the given index.

- `insert(maxHeap* maxHeap, int value)`: This function inserts a new element into the max heap.

- `removeMax(maxHeap* maxHeap)`: This function removes the maximum element from the max heap.

- `removeMin(maxHeap* maxHeap)`: This function removes the minimum element from the max heap.

- `removeValue(maxHeap* maxHeap, int value)`: This function removes an element with a specific value from the max heap.

- `freeMaxHeap(maxHeap* maxHeap)`: This function frees the memory allocated for the max heap.

- `heapSort(int arr[], int n)`: This function performs heap sort on an array of elements.
&emsp;

The implementation of the MinHeap is nearly the same except that the value of parent should be lower than childs.

&emsp;

## Empirical Analysis
---
The Empirical test is implemented in the below code:

'[empirical_test.c](empirical_test.c)'

We tested the operation time(second) of insertion, removeMax and heap sort of max heap with a range of size from 10 to 10000000. 

| n       | Insert    | Remove    | Heap Sort |
| ------- | --------- | --------- | --------- |
| 10      | 0.000001  | 0.000001  | 0.000009  |
| 50      | 0.000005  | 0.000009  | 0.000021  |
| 100     | 0.000011  | 0.000020  | 0.000032  |
| 500     | 0.000059  | 0.000090  | 0.000153  |
| 1000    | 0.000137  | 0.000236  | 0.000333  |
| 5000    | 0.000964  | 0.001394  | 0.002513  |
| 10000   | 0.001740  | 0.002515  | 0.004587  |
| 30000   | 0.002978  | 0.004115  | 0.010398  |
| 50000   | 0.005292  | 0.006378  | 0.015519  |
| 75000	  | 0.007953  | 0.010662  | 0.016918  |
| 100000  |	0.011516  |	0.014785  |	0.022667  |
| 500000  |	0.06378   | 0.084254  |	0.131318  |
| 1000000 | 0.133289  |	0.172305  |	0.282721  |
| 5000000 |	0.739842  |	0.957125  |	1.890959  |
|10000000 |	1.57253   |	2.005094  |	3.710743  |

&emsp;

The empirical data indeed show a logarithmic time complexity from n = 10-30000
for insertion and removeMax. 

![Time complexity_2]

However, the data display more of a linear trend for greater sizes up to 500000000.
The operation of heap sort only starts to show O(${n}log{_2}{n}$) trend when n is greater than 100000000.

![Time complexity_1]
![Time complexity_3]

After checking that our implementaion is correct, there might be some possible reasons that we observe a linear time complexity. 
* The distribution of data we generate randomly
* Hardware and Software envirmoment
* Size not big enough
* Efficiency of this implementation 

Overall, further research are required to interpret our result.


&emsp;

[Time complexity_1]: n=10000000.png
[Time complexity_2]: n=30000.png
[Time complexity_3]: n=500000000.png

## Advantages and Disadvantages of Heap
---

The advantages of using a max heap data structure include:

- Finding the maximum element in constant time.

- Inserting a new element into the max heap in logarithmic time.

- Removing the maximum element from the max heap in logarithmic time.

The disadvantages of using a max heap data structure include:

- Finding the minimum element requires iterating through the entire heap, which takes linear time.

- Removing an element with a specific value requires iterating through the entire heap, which takes linear time.

&emsp;

## Applications 
---

- Priority Queues: Heaps can be used to implement priority queues, where elements are stored and retrieved based on their priority.

- Sorting Algorithms: Heap sort is a popular heap-based sorting algorithm that has a time complexity of O(${n}log{_2}{n}$) as discussed above.

- Graph Algorithms: Heaps are used in graph algorithms such as Dijkstra's algorithm for finding the shortest path in a graph.

- Memory Management: Heaps are used in memory management systems to allocate and deallocate memory dynamically.

- Operating Systems: Heaps are used in operating systems for various purposes such as scheduling processes and managing virtual memory.

&emsp;

## Conclusion
---
Heap is a fundamental data structure in computer science, with various applications in areas such as algorithms, data structures, and operating systems. We have explored the heap's time and space complexities make it an efficient data structure for many applications.

## References
---

1. OpenGenus IQ. (n.d.). Time and Space Complexity of Heap. Retrieved April 25, 2023, from https://iq.opengenus.org/time-and-space-complexity-of-heap/#insertion
2. Wikipedia. (2023, March 7). Binary heap. In Wikipedia. Retrieved April 25, 2023, from https://en.wikipedia.org/wiki/Binary_heap
3. Programiz. (n.d.). Heap Data Structure. Retrieved April 25, 2023, from https://www.programiz.com/dsa/heap-data-structure
4. GeeksforGeeks. (n.d.). Heap Data Structure - Introduction and Heapify. Retrieved April 25, 2023, from https://www.geeksforgeeks.org/introduction-to-heap-data-structure-and-algorithm-tutorials/