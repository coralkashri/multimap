#ifndef MULTIMAP_HASH_TABLE_META_DATA_H
#define MULTIMAP_HASH_TABLE_META_DATA_H

#include <string>

class multimap_metadata {
public:
    explicit multimap_metadata(std::string &&description) : entry_description(description) {}

    [[nodiscard]] std::string get_description() const { return entry_description; }

private:
    std::string entry_description;
};

#endif //MULTIMAP_HASH_TABLE_META_DATA_H