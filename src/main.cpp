#include <iostream>
#include "multimap.h"

int func() { return 0; }
int func2() { return 1; }
int func3() { return 2; }
int func4() { return 3; }

int main() {
    multimap<int(*)()> mp = {
            {
                    {{{"key1", "key2", "key3"}, "description1"}, func},
                    {{std::initializer_list<std::string>{"key5", "key6"}, "description1"}, func2},
                    {{{"key7"}, "description1"}, func3},
                    {{{"key8", "key9", "key10", "key11"}, "description1"}, func4}
            }
    };
    return EXIT_SUCCESS;
}