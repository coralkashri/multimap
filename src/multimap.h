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
#include <set>
#include <memory>
#include "multimap_entry.h"

template <typename KEY_T, typename VAL_T>
class multimap{
public:
private:
    std::vector<std::shared_ptr<multimap_entry<KEY_T, VAL_T>>> entries;

};

#endif //MULTIMAP_MULTIMAP_H