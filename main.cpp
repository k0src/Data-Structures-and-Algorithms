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


using namespace std;

// Reversing a queue with a stack
void reverse(queue<int>& q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    ArrayQueue aq(5);
    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    aq.dequeue();
    aq.dequeue();
    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    cout << aq;
}