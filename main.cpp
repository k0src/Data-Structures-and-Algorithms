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

using namespace std;

int main()
{
    int nums[] = { 1, 5, 2, 7, 3, 4, 12, 9 };
    Heap heap(10);

    for (int n : nums)
        heap.insert(n);

    for (int i = size(nums) - 1; i >= 0; i--) {
        nums[i] = heap.root();
        heap.remove();
    }

    for (int& n : nums)
        cout << n << endl;

    return 0;
}