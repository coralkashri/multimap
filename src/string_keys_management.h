#ifndef MULTIMAP_STRING_KEYS_MANAGEMENT_H
#define MULTIMAP_STRING_KEYS_MANAGEMENT_H

#include <vector>
#include <string>
#include <type_traits>
#include <ranges>

class string_keys_management {
public:
    string_keys_management(const string_keys_management&) = default;
    string_keys_management(string_keys_management&&) = default;
    string_keys_management& operator=(const string_keys_management&) = default;
    string_keys_management& operator=(string_keys_management&&) = default;

    string_keys_management(const std::initializer_list<std::string>& keys, const std::string &description = "")
            : description(description) {
        auto filtered_keys = keys | std::views::filter([] (auto &key) { return !key.empty(); }) | std::views::common;
        this->keys.insert(this->keys.begin(), filtered_keys.begin(), filtered_keys.end());
    }

    bool operator==(const std::string &ref) const {
        auto it = std::find(keys.begin(), keys.end(), ref);
        return it != keys.end();
    }

    bool operator==(const string_keys_management &ref) const {
        for (auto &key : ref.keys) {
            if (key == *this) return true;
        }
        return false;
    }

    bool operator!=(const std::string &ref) const {
        return !(*this == ref);
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

    [[nodiscard]] std::string get_description() const {return description; }

private:
    std::vector<std::string> keys;
    std::string description;
};

#endif //MULTIMAP_STRING_KEYS_MANAGEMENT_H