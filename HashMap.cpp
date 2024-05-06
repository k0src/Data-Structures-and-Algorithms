#include "HashMap.h"
#include <stdexcept>

HashMap::HashMap() {
    // Initialize an array of pointers to lists with the given size
    hashMap = new std::list<KeyValue>*[size]();
}

HashMap::~HashMap() {
    // Deallocate memory for each list in the array
    for (int i = 0; i < size; ++i) {
        if (hashMap[i] != nullptr) {
            delete hashMap[i];
        }
    }
    // Deallocate memory for the array itself
    delete[] hashMap;
}

void HashMap::put(int key, const std::string& value) {
    // Compute the index to store the key-value pair
    int index = hash(key);
    // If the bucket is empty, create a new list
    if (hashMap[index] == nullptr) {
        hashMap[index] = new std::list<KeyValue>;
    }
    // Get the bucket associated with the index
    auto bucket = hashMap[index];
    // Check if the key already exists in the bucket
    for (auto& entry : *bucket) {
        // If the key exists, update its value and return
        if (entry.getKey() == key) {
            entry.value = value;
            return;
        }
    }
    // If the key doesn't exist, create a new key-value pair and add it to the bucket
    auto kv = new KeyValue(key, value);
    bucket->push_back(*kv);
}

std::string HashMap::get(int key) {
    // Compute the index to retrieve the key-value pair
    int index = hash(key);
    // Get the bucket associated with the index
    auto bucket = hashMap[index];
    // If the bucket is not empty, search for the key
    if (bucket != nullptr) {
        for (auto& entry : *bucket) {
            // If the key is found, return its value
            if (entry.getKey() == key) {
                return entry.getValue();
            }
        }
    }
    // If the key is not found, return an empty string
    return "";
}

void HashMap::remove(int key) {
    // Compute the index to remove the key-value pair
    int index = hash(key);
    // Get the bucket associated with the index
    auto bucket = hashMap[index];
    // If the bucket is not empty, search for the key
    if (bucket != nullptr) {
        auto it = bucket->begin();
        while (it != bucket->end()) {
            // If the key is found, erase the key-value pair from the bucket and return
            if (it->getKey() == key) {
                it = bucket->erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    // If the key is not found, throw an exception
    throw std::invalid_argument("Key not found.");
}

int HashMap::hash(int key) const {
    // Compute the hash value by taking the absolute value of the key modulo the size
    key = abs(key);
    return key % size;
}