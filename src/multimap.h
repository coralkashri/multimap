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
#include <unordered_map>
#include "string_keys_management.h"
#include "iterator_helpers/use_collection_iterator.h"
#include "hash_functions.h"

template <typename K, typename V>
using multimap_container_type = std::unordered_map<K, V, my_utils::my_hasher>;

using multimap_key_type = string_keys_management;

template <template <typename ...> typename Container, typename K, typename V>
using my_collection_iterator = use_collection_iterator_without_reverse<Container, K, V>;

template <typename V>
class multimap : public my_collection_iterator<multimap_container_type, multimap_key_type, V> {
public:
    // A convenient access to inherited type members
    using base_types = my_collection_iterator<multimap_container_type, multimap_key_type, V>;

public:
    using items_type = multimap_container_type<multimap_key_type, V>;

public:
    multimap() = default;
    multimap(const items_type &ref) : items(ref) {}
    multimap& operator=(const items_type &ref) {
        items = ref;
        return *this;
    }

    V& at(const std::string &key) {
        return items.at({key});
    }

    void insert(const string_keys_management &keys, V val) {
        items.insert({keys, val});
    }

    /* Required Iterators Access Methods */

    typename base_types::iterator begin() { return items.begin(); }
    typename base_types::iterator end() { return items.end(); }
    [[nodiscard]] typename base_types::const_iterator cbegin() const { return items.cbegin(); }
    [[nodiscard]] typename base_types::const_iterator cend() const { return items.cend(); }

    bool empty() { return items.empty(); }
    typename base_types::size_type size() { return items.size(); }

private:
    items_type items;
};

#endif //MULTIMAP_MULTIMAP_H