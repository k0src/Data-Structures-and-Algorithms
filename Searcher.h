#ifndef STRUCTURESALGOS_SEARCHER_H
#define STRUCTURESALGOS_SEARCHER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Searcher {
public:
    int linearSearch(const vector<int>& array, int target);
    int binarySearchRecursive(const vector<int>& array, int start, int end, int target);
    int binarySearchIterative(const vector<int>& array, int target);
    int ternarySearch(vector<int>& array, int start, int end, int target);
    int jumpSearch(vector<int>& array, int target);
    int exponentialSearch(vector<int>& array, int target);
};

#endif //STRUCTURESALGOS_SEARCHER_H