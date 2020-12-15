#ifndef MULTIMAP_MULTIMAP_H
#define MULTIMAP_MULTIMAP_H

#include <iostream>
#include <vector>
#include <map>
#include "string_keys_management.h"

template <typename V>
using multimap = std::map<string_keys_management, V>;

#endif //MULTIMAP_MULTIMAP_H