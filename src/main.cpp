#include <iostream>
#include "multimap.h"
#include "keys_management.h"

int main() {
    multimap<std::string> mp = {
            {
                    {{{"key1", "key2", "key3"}, "description1"}, "value"},
                    {{{"key5", "key6"}, "description1"}, "value2"},
                    {{{"key7"}, "description1"}, "value2"},
                    {{{"key8", "key9", "key10", "key11"}, "description1"}, "value2"}
            }
    };
    return EXIT_SUCCESS;
}