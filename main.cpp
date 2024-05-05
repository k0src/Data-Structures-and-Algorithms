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

using namespace std;

int main()
{
    QueueStack queueStack;
    queueStack.push(10);
    queueStack.push(20);
    queueStack.push(30);
    queueStack.push(40);
    cout << queueStack.pop();
}