#include <iostream>
#include <cmath>
#include <sstream>
#include "Array.h"
#include <vector>
#include <list>
#include <algorithm>
#include "Node.h"
#include <unordered_set>
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

bool isRotation(const string& str1, const string& str2) {
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str2;
    if (!(search(temp.begin(), temp.end(), str2.begin(), str2.end()) != temp.end()))
        return false;

    return true;
}

string removeDuplicates(const string& str) {
    set<char> chars;
    string res;

    for (char c : str) {
        if (!chars.contains(c)) {
            chars.insert(c);
            res.push_back(c);
        }
    }
    return res;
}

char mostRepeated(const string& str) {
    map<char, int> chars;
    char res;
    int freq = 0;

    for (char c : str)
        chars[c]++;

    for (auto p : chars) {
        if (p.second > freq) {
            freq = p.second;
            res = p.first;
        }
    }
    return res;
}

// Function to trim leading and trailing spaces
std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return ""; // no content
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to split a string by spaces
std::vector<std::string> split(const std::string &str) {
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to join a vector of strings with a delimiter
std::string join(const std::vector<std::string> &words, const std::string &delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0)
            oss << delimiter;
        oss << words[i];
    }
    return oss.str();
}

// Function to capitalize each word in a sentence
std::string reformat(const std::string &sentence) {
    if (sentence.empty() || trim(sentence).empty()) {
        return "";
    }

    std::string trimmedSentence = trim(sentence);
    std::vector<std::string> words = split(trimmedSentence);

    for (auto &word : words) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        word[0] = std::toupper(word[0]);
    }
    return join(words, " ");
}

int main()
{
    cout << reformat("     trees     are    awesome");
    return 0;
}
