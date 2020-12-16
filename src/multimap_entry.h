#ifndef MULTIMAP_MULTIMAP_ENTRY_H
#define MULTIMAP_MULTIMAP_ENTRY_H

#include <memory>
#include "multimap_metadata.h"

template <typename KEY_T, typename VAL_T>
class multimap_entry {
public:
    multimap_entry(const KEY_T &source_key, std::shared_ptr<VAL_T> value_ptr, std::shared_ptr<multimap_metadata> metadata_ptr)
    : source_key(source_key), value_ptr(std::move(value_ptr)), metadata_ptr(std::move(metadata_ptr))
    {}

    [[nodiscard]] KEY_T get_source_key() const { return source_key; }

    [[nodiscard]] std::shared_ptr<VAL_T> get_value_ptr() const { return value_ptr; }

    [[nodiscard]] std::shared_ptr<multimap_entry> get_metadata_ptr() const { return metadata_ptr; }

private:
    KEY_T source_key;
    std::shared_ptr<VAL_T> value_ptr;
    std::shared_ptr<multimap_metadata> metadata_ptr;
};

#endif //MULTIMAP_MULTIMAP_ENTRY_H