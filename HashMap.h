#ifndef STRUCTURESALGOS_HASHMAP_H
#define STRUCTURESALGOS_HASHMAP_H

#include <string>
#include <list>
#include "KeyValue.h"

class HashMap {
public:
    HashMap();
    ~HashMap();
    void put(int key, const std::string& value);
    std::string get(int key);
    void remove(int key);
private:
    int size = 5;
    std::list<KeyValue>** hashMap;

    int hash(int key) const;
};


#endif //STRUCTURESALGOS_HASHMAP_H