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

using namespace std;

int main()
{
    PriorityQueue priorityQueue(5);
    priorityQueue.add(10);
    priorityQueue.add(30);
    priorityQueue.add(20);
    priorityQueue.add(40);
    priorityQueue.add(5);
    priorityQueue.reverse(3);

    cout << priorityQueue;
}