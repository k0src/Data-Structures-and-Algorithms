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

int main()
{
    vector<int> array = { 1, 5, 2, 3, 6, 4, 10 };
    insertionSort(array);
    for (int n : array)
        cout << n << endl;
    return 0;
}