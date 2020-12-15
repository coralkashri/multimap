#ifndef MULTIMAP_STRING_KEYS_MANAGEMENT_H
#define MULTIMAP_STRING_KEYS_MANAGEMENT_H

#include <vector>
#include <string>
#include <type_traits>

class string_keys_management {
public:
    string_keys_management(const string_keys_management&) = default;
    string_keys_management(string_keys_management&&) = default;
    string_keys_management& operator=(const string_keys_management&) = default;
    string_keys_management& operator=(string_keys_management&&) = default;

    string_keys_management(const std::initializer_list<std::string>& keys, const std::string &description = "")
    : keys(keys), description(description) {}

    bool operator==(const std::string &ref) {
        auto it = std::find(keys.begin(), keys.end(), ref);
        return it != keys.end();
    }

    bool operator!=(const std::string &ref) {
        return !(*this == ref);
    }

    bool operator<(const string_keys_management &ref) const {
        return ref.description < description;
    }

    friend std::ostream& operator<<(std::ostream& out, const string_keys_management &ref) {
        out << "[";
        for (auto &key : ref.keys) {
            out << key;
            if (&key != &ref.keys.back()) {
                out << ",";
            }
        }
        out << "]";
        if (!ref.description.empty()) {
            out << " - " << ref.description;
        }
        return out;
    }

private:
    std::vector<std::string> keys;
    std::string description;
};

#endif //MULTIMAP_STRING_KEYS_MANAGEMENT_H