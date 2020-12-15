#include <iostream>
#include "multimap.h"
#include "keys_management.h"
// ................ Tests ...................

int main() {
    multimap<std::string> mp = {
            {
                    {{{"key1", "key2", "key3"}, "description1"}, "value"},
                    {{{"key4", "key5", "key6"}, "description1"}, "value2"}
            }
    };
    return EXIT_SUCCESS;
}