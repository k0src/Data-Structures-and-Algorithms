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

using namespace std;

int getKthLargest(int array[], int size, int k) {
    if (k > size)
        return -1;

    Heap heap(10);
    for (int i = 0; i < size; i++)
        heap.insert(array[i]);

    for (int i = 0; i < k; i++) {
        heap.remove();
    }
    return heap.root();
}

int main()
{
    int array[] = { 8, 5, 2, 3, 1, 7, 12 };
    int k = 4;
    cout << getKthLargest(array, size(array), k);
    return 0;
}