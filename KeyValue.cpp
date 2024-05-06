#include "KeyValue.h"

KeyValue::KeyValue() {
    this->key = 0;
    this->value = nullptr;
}

KeyValue::KeyValue(int key, std::string value) {
    this->key = key;
    this->value = value;
}