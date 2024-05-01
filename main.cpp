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

using namespace std;

int main()
{
    string str = "(<>}";
    ExpressionChecker exp;
    cout << boolalpha << exp.isBalanced(str);
}