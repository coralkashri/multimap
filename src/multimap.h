#ifndef MULTIMAP_MULTIMAP_H
#define MULTIMAP_MULTIMAP_H

#include <iostream>
#include <vector>
#include <map>
#include "string_keys_management.h"

template <typename V>
class multimap {
public:
    multimap(const std::map<string_keys_management, V> &ref) : values(ref) {}
    multimap& operator=(const std::map<string_keys_management, V> &ref) {
        values = ref;
    }

    V& at(const std::string &key) {
        return values.at(key);
    }

    void insert(const string_keys_management &keys, V val) {
        values.insert({keys, val});
    }

private:
    std::map<string_keys_management, V> values;
};

#endif //MULTIMAP_MULTIMAP_H