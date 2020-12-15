/**
 * Iterators Origin:
 * https://github.com/koralkashri/cppsenioreas-iterators/blob/8a8684ae6d56cf2c5a303f5a8912c4eda5be135c/main.cpp#L254
 * ...
 * https://github.com/koralkashri/cppsenioreas-iterators/blob/8a8684ae6d56cf2c5a303f5a8912c4eda5be135c/main.cpp#L289
 */

#ifndef MULTIMAP_MULTIMAP_H
#define MULTIMAP_MULTIMAP_H

#include <iostream>
#include <vector>
#include <map>
#include "string_keys_management.h"
#include "iterator_helpers/use_collection_iterator.h"

template <template <typename ...> typename Container, typename K, typename V>
using my_collection_iterator = use_collection_iterator<Container, K, V>;

template <typename V>
class multimap : public my_collection_iterator<std::map, string_keys_management, V> {
public:
    // A convenient access to inherited type members
    using base_types = my_collection_iterator<std::map, string_keys_management, V>;

    multimap() = default;
    multimap(const std::map<string_keys_management, V> &ref) : items(ref) {}
    multimap& operator=(const std::map<string_keys_management, V> &ref) {
        items = ref;
    }

    V& at(const std::string &key) {
        return items.at(key);
    }

    void insert(const string_keys_management &keys, V val) {
        items.insert({keys, val});
    }

    /* Required Iterators Access Methods */

    typename base_types::iterator begin() { return items.begin(); }
    typename base_types::iterator end() { return items.end(); }
    [[nodiscard]] typename base_types::const_iterator cbegin() const { return items.cbegin(); }
    [[nodiscard]] typename base_types::const_iterator cend() const { return items.cend(); }
    typename base_types::reverse_iterator rbegin() { return items.rbegin(); }
    typename base_types::reverse_iterator rend() { return items.rend(); }
    [[nodiscard]] typename base_types::const_reverse_iterator crbegin() const { return items.crbegin(); }
    [[nodiscard]] typename base_types::const_reverse_iterator crend() const { return items.crend(); }

    bool empty() { return items.empty(); }
    typename base_types::size_type size() { return items.size(); }

private:
    std::map<string_keys_management, V> items;
};

#endif //MULTIMAP_MULTIMAP_H