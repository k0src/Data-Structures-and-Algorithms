#include "ExpressionChecker.h"
#include <stack>
#include <algorithm>

ExpressionChecker::ExpressionChecker() {
    // Bracket arrays
    leftBrackets = {'(', '<', '[', '{'};
    rightBrackets = {')', '>', ']', '}'};
}

bool ExpressionChecker::isBalanced(const std::string &str) {
    std::stack<char> stack;

    // Iterate over string
    for (char c: str) {
        // If current character is a left bracket
        if (isLeftBracket(c))
            // Push onto the stack
            stack.push(c);
        // If current character is a right bracket
        if  (isRightBracket(c)) {
            // If stack is empty, return false
            if (stack.empty())
                return false;
            // Pop the top, store in variable
            char top = stack.top();
            stack.pop();
            // If brackets don't match - return false
            if (!bracketMatch(top, c))
                return false;
        }
    }
    return stack.empty();
}

// Refactored to be more concise.
bool ExpressionChecker::isLeftBracket(char c) {
    return find(leftBrackets.begin(), leftBrackets.end(), c) != leftBrackets.end();

}

bool ExpressionChecker::isRightBracket(char c) {
    return find(rightBrackets.begin(), rightBrackets.end(), c) != rightBrackets.end();
}

// Comparing indices of the elements in the string
bool ExpressionChecker::bracketMatch(char left, char right) {
    return (std::find(leftBrackets.begin(), leftBrackets.end(), left) - leftBrackets.begin() ==
            std::find(rightBrackets.begin(), rightBrackets.end(), right) - rightBrackets.begin());
}