#ifndef MULTIMAP_KEYS_MANAGEMENT_H
#define MULTIMAP_KEYS_MANAGEMENT_H

#pragma GCC warning "This header is experimental and not fully implemented yet. Use string_keys_management.h instead.")

#include <vector>
#include <string>
#include <type_traits>

template <typename T>
concept Stringable = requires(T t) {
    { std::string(t) };
};

class keys_management {
public:
    template <Stringable... Keys>
    keys_management(const Keys& ...keys, const std::string &description = "") : description(description) {
        this->keys.insert(this->keys.begin(), {std::string(keys)...});
    }

    bool operator==(const std::string &ref) {
        auto it = std::find(keys.begin(), keys.end(), ref);
        return it != keys.end();
    }

    bool operator!=(const std::string &ref) {
        return !(*this == ref);
    }

private:
    std::vector<std::string> keys;
    std::string description;
};

#endif //MULTIMAP_KEYS_MANAGEMENT_H