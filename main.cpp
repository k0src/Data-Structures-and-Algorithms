#include <iostream>
#include "Array.h"
#include <vector>
#include <list>
#include <algorithm>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

// commit to the hub

int main()
{
    LinkedList l;
    l.addLast(10);
    l.addLast(20);
    l.addLast(30);
    l.addLast(40);
    l.addLast(50);

    // two pointers that are k-1 nodes apart.

//    for (int i = 0; i < 4; i++) {
//        cout << l.toArray()[i] << endl;
//    }

    cout << l.middle();
}