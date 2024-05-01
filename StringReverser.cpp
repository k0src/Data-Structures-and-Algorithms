#include "StringReverser.h"
#include <string>
#include <stack>

std::string StringReverser::reverse(const std::string &str) {
    std::stack<char> stack;

    for (char c: str) {
        stack.push(c);
    }

    std::string rev;

    while(!stack.empty()) {
        rev.push_back(stack.top());
        stack.pop();
    }

    return rev;
}