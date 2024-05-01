#include <iostream>
#include "Array.h"
#include <vector>
#include <list>
#include <algorithm>
#include "Node.h"
#include "LinkedList.h"
#include <stack>
#include "StringReverser.h"

using namespace std;

int main()
{
    string str = "A string to be reversed";
    StringReverser sr;
    cout << sr.reverse();
}