#ifndef STRUCTURESALGOS_EXPRESSIONCHECKER_H
#define STRUCTURESALGOS_EXPRESSIONCHECKER_H

#include <string>
#include <vector>

class ExpressionChecker {
public:
    ExpressionChecker();
    bool isBalanced(const std::string& str);
private:
    bool isLeftBracket(char c);
    bool isRightBracket(char c);
    bool bracketMatch(char left, char right);
    std::vector<char> leftBrackets;
    std::vector<char> rightBrackets;
};

#endif //STRUCTURESALGOS_EXPRESSIONCHECKER_H