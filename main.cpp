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

using namespace std;

char firstNonRepeatedCharacter(string& str) {
    unordered_map<char, int> map;

    for (char& c: str) {
        if (map.find(c) == map.end()) {
            map[c] = 1;
        }
        else {
            map[c] = map[c] + 1;
        }
    }

    for (char& c: str) {
        if (map[c] == 1) {
            return c;
        }
    }
    return -1;
}

int main()
{
    string s = "a green apple";
    cout << firstNonRepeatedCharacter(s);
}