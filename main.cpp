#include <iostream>
#include <cmath>
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

bool isVowel(const char& c) {
    set<char> vowels {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    return vowels.find(c) != vowels.end();
}

int countVowels(const string& str) {
    int count = 0;
    for (const char& c : str)
        if (isVowel(c))
            count++;
    return count;
}

string reverseStringStack(const string& str) {
    stack<char> s;
    string result;
    for (const char& c : str)
        s.push(c);

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

string reverseStringBack(const string& str) {
    string result;
    for (int i = str.size() - 1; i >= 0; i--)
        result.push_back(str[i]);
    return result;
}

string reverseWords(const string& str) {
    string result;
    int j = str.size();
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            int start = (i == 0) ? 0 : i + 1;
            int len = j - start;
            result.append(str.substr(start, len) + " ");
            j = i;
        }
    }
    return result;
}

int main()
{
    cout << reverseWords("hello world this is a string");
    return 0;
}
