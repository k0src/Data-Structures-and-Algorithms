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

using namespace std;

int main()
{
    Tree tree;
    tree.add(7);
    tree.add(4);
    tree.add(9);
    tree.add(1);
    tree.add(6);
    tree.add(8);
    tree.add(10);

    cout << tree.size();
    return 0;
}