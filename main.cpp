#include <iostream>
#include "Array.h"
#include <vector>
#include <list>
#include <algorithm>
#include "Node.h"
#include "LinkedList.h"
#include <stack>
#include "StringReverser.h"
#include <unordered_map>
#include "ExpressionChecker.h"
#include "Stack.h"
#include <queue>
#include "ArrayQueue.h"
#include "QueueReverser.h"
#include "StackQueue.h"
#include "PriorityQueue.h"
#include "QueueStack.h"
#include <unordered_map>
#include "HashMap.h"
#include <string>
#include "Tree.h"
#include "AVLTree.h"
#include "Heap.h"
#include "PriorityQueueWithHeap.h"
#include "Heapify.h"
#include "Trie.h"
#include "HashTrie.h"
#include "Graph.h"
#include "WeightedGraph.h"

using namespace std;

void bubbleSort(vector<int>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        bool isSorted;
        for (int j = 1; j < array.size() - i; j++) {
            isSorted = true;
            if (array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            return;
    }
}

void selectionSort(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        int minIndex = i;
        for (int j = i; j < array.size(); j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void insertionSort(vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        int current = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

// Function to merge two halves
void merge(int left[], int leftSize, int right[], int rightSize, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            result[k++] = left[i++];
        else
            result[k++] = right[j++];
    }

    while (i < leftSize)
        result[k++] = left[i++];

    while (j < rightSize)
        result[k++] = right[j++];
}

// Function to implement merge sort
void mergeSort(int array[], int size) {
    if (size < 2)
        return;

    // Divide array in half
    int middle = size / 2;

    int *left = new int[middle];
    int *right = new int[size - middle];

    for (int i = 0; i < middle; i++)
        left[i] = array[i];

    for (int i = middle; i < size; i++)
        right[i - middle] = array[i];

    // Sort each half
    mergeSort(left, middle);
    mergeSort(right, size - middle);

    // Merge
    merge(left, middle, right, size - middle, array);

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

int partition(vector<int>& array, int start, int end) {
    int pivot = array[end];
    int boundary = start - 1;

    for (int i = start; i <= end; i++) {
        if (array[i] <= pivot) {
            boundary++;
            swap(array[i], array[boundary]);
        }
    }
    return boundary;
}

void quickSort(vector<int>& array, int start, int end) {
    // Base condition
    if (start >= end)
        return;
    // Partition the array
    int boundary = partition(array, start, end);
    // Sort left
    quickSort(array, start, boundary - 1);
    // Sort right
    quickSort(array, boundary + 1, end);
}

int main()
{
    vector<int> array = { 1, 5, 2, 3, 6, 4, 10 };
//    int array[] = { 1, 5, 2, 3, 6, 4, 10 };
//    int size = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, array.size() - 1);
    for (int n : array)
        cout << n << endl;
    return 0;
}