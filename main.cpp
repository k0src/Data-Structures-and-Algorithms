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

using namespace std;

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(1);
    stack.pop();
    cout << stack.min();
}