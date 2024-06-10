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

int linearSearch(const vector<int>& array, int target) {
    for (int i = 0; i < array.size(); i++)
        if (array[i] == target)
            return i;
    return -1;
}

int binarySearchRecursive(const vector<int>& array, int start, int end, int target) {
    if (end >= start) {
        int mid = (end + start) / 2;

        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
            return binarySearchRecursive(array, start, mid - 1, target);
        else
            return binarySearchRecursive(array, mid + 1, end, target);
    }
    else {
        return -1;
    }
}

int binarySearchIterative(const vector<int>& array, int target) {
    int start = 0, end = array.size() - 1;

    while (end >= start) {
        int mid = (end + start) / 2;

        if (array[mid] == target) {
            return mid;
        }
        else if (array[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> array = { 1, 2, 3, 5, 6, 10, 12, 23, 34 };
    int target = 10;
    cout << binarySearchIterative(array, target);
    return 0;
}
