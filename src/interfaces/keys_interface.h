#ifndef BANKMANAGEMENT_KEYS_INTERFACE_H
#define BANKMANAGEMENT_KEYS_INTERFACE_H

#include <iostream>
#include "../external_tools/template_base_interface_impl.h"

class keys_interface {
public:
    virtual ~keys_interface() = default;
    friend std::ostream& operator<<(std::ostream& out, keys_interface* elem);
    virtual bool operator==(keys_interface &elem) {
        return typeid(this) == typeid(elem);
    };
};

// Interface implementation specialization for shape_interface
template <typename T>
class template_base_interface_implementation<keys_interface, T> : public keys_interface {
public:
    explicit template_base_interface_implementation(T& impl_obj) : m_impl_obj(impl_obj) {}

    // Interface should be fully implemented here
    // region [Interface Implementation Begin]

    friend std::ostream& operator<<(std::ostream& out, keys_interface* elem) {
        return out << elem;
    }

    bool operator==(keys_interface &elem) {
        return m_impl_obj == elem;
    }

    // endregion [Interface Implementation End]

private:
    T& m_impl_obj; // Contain the target spe`cialized class instance
};

#endif //BANKMANAGEMENT_KEYS_INTERFACE_H