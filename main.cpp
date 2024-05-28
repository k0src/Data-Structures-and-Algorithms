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

int main()
{
    WeightedGraph weightedGraph;
    weightedGraph.addNode("A");
    weightedGraph.addNode("B");
    weightedGraph.addNode("C");
    weightedGraph.addEdge("A", "B", 3);
    weightedGraph.addEdge("A", "C", 2);
    weightedGraph.print();
    return 0;
}