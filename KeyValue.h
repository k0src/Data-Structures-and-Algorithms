#ifndef STRUCTURESALGOS_KEYVALUE_H
#define STRUCTURESALGOS_KEYVALUE_H

#include <string>

class KeyValue {
public:
    KeyValue();
    KeyValue(int key, std::string value);
    int getKey() const { return key; }
    std::string getValue() const { return value; }
private:
    int key;
    std::string value;
    friend class HashMap;
};


#endif //STRUCTURESALGOS_KEYVALUE_H
