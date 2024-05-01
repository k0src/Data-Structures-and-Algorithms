#include "ExpressionChecker.h"
#include <stack>

bool ExpressionChecker::isBalanced(const std::string &str) {
    std::stack<char> stack;

    for (char c: str) {
        if (c == '(' || c == '<' || c == '[' || c == '{')
            stack.push(c);
        if (c == ')' || c == '>' || c == ']' || c == '}') {
            if (stack.empty())
                return false;
            char top = stack.top();
            stack.pop();
            if (
                    (c == ')' && top != '(') ||
                    (c == '>' && top != '<') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')
                ) return false;
        }
    }
    return stack.empty();
}