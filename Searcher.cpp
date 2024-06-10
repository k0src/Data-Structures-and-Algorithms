#include "Searcher.h"

using namespace std;

int Searcher::linearSearch(const vector<int>& array, int target) {
    for (int i = 0; i < array.size(); i++)
        if (array[i] == target)
            return i;
    return -1;
}

int Searcher::binarySearchRecursive(const vector<int>& array, int start, int end, int target) {
    if (end >= start) {
        int mid = (end + start) / 2;

        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
            return binarySearchRecursive(array, start, mid - 1, target);
        else
            return binarySearchRecursive(array, mid + 1, end, target);
    }
    else {
        return -1;
    }
}

int Searcher::binarySearchIterative(const vector<int>& array, int target) {
    int start = 0, end = array.size() - 1;

    while (end >= start) {
        int mid = (end + start) / 2;

        if (array[mid] == target) {
            return mid;
        }
        else if (array[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int Searcher::ternarySearch(vector<int>& array, int start, int end, int target) {
    int partitionSize = (end - start) / 3;

    if (start > end)
        return -1;

    int mid1 = start + partitionSize;
    int mid2 = end - partitionSize;

    if (array[mid1] == target)
        return mid1;
    if (array[mid2] == target)
        return mid2;
    if (array[mid1] > target)
        return ternarySearch(array, start, mid1 - 1, target);
    if (array[mid2] < target)
        return ternarySearch(array, mid2 + 1, end, target);
    return ternarySearch(array, mid1 + 1, mid2 - 1, target);
}

int Searcher::jumpSearch(vector<int>& array, int target) {
    int blockSize = (int) sqrt(array.size());
    int start = 0, next = blockSize;

    while (start < array.size() && array[next - 1] < target) {
        start = next;

        next += blockSize;
        if (next > array.size()) next = array.size();
    }

    for (int i = start; i < next; i++) {
        if (array[i] == target)
            return  i;
    }
    return -1;
}

int Searcher::exponentialSearch(vector<int>& array, int target) {
    int bound = 1;
    while (bound < array.size() && array[bound] < target)
        bound *= 2;

    int start = bound / 2;
    int end = std::min(bound, (int) array.size() - 1);

    return binarySearchRecursive(array, start, end, target);
}