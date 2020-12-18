# C++ Multimap
C++ map with multiple keys.

# Examples
```cpp
multimap<std::string, int(*)()> mp = {
         {
                {{{"key1", "key2", "key3"}, "description1"}, func},
                {{std::initializer_list<std::string>{"key5", "key6"}, "description2"}, func2},
                {{std::initializer_list<std::string>{"key7"}, "description3"}, func3},
                {{{"key8", "key9", "key10", "key11"}, "description4"}, func4}
         }
};

std::cout << mp.at("key1")() << "\n"; // 0
std::cout << mp.at("key2")() << "\n"; // 0
std::cout << mp.at("key3")() << "\n"; // 0
std::cout << mp.at("key5")() << "\n"; // 1
std::cout << mp.at("key6")() << "\n"; // 1
std::cout << mp.at("key7")() << "\n"; // 2
std::cout << mp.at("key8")() << "\n"; // 3
std::cout << mp.at("key11")() << "\n"; // 3

for (auto &keys_relation : mp.get_key_relations()) {
    std::cout << keys_relation << std::endl;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    [key1, key2, key3] - description1
    [key5, key6] - description2
    [key7] - description3
    [key8, key9, key10, key11] - description4
*/
```
