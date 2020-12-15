/**
 * Origin:
 * https://github.com/koralkashri/cppsenioreas-iterators
 */

#ifndef MULTIMAP_USE_COLLECTION_ITERATOR_H
#define MULTIMAP_USE_COLLECTION_ITERATOR_H

#include <type_traits>
#include <iterator>

template <template <typename ...> typename Container, typename K, typename V>
concept IteratorsFriendlyContainerType = requires (Container<K, V> container) {
    typename decltype(container)::pointer;
    typename decltype(container)::const_pointer;
    typename decltype(container)::reference;
    typename decltype(container)::const_reference;
    typename decltype(container)::iterator;
    typename decltype(container)::const_iterator;
    typename decltype(container)::reverse_iterator;
    typename decltype(container)::const_reverse_iterator;
    typename decltype(container)::size_type;
};

template <template <typename ...> typename Container, typename K, typename V>
requires IteratorsFriendlyContainerType<Container, K, V>
struct use_collection_iterator {
    typedef typename Container<K, V>::pointer pointer;
    typedef typename Container<K, V>::const_pointer const_pointer;
    typedef typename Container<K, V>::reference reference;
    typedef typename Container<K, V>::const_reference const_reference;
    typedef typename Container<K, V>::iterator iterator;
    typedef typename Container<K, V>::const_iterator const_iterator;
    typedef typename Container<K, V>::reverse_iterator reverse_iterator;
    typedef typename Container<K, V>::const_reverse_iterator const_reverse_iterator;
    typedef typename Container<K, V>::size_type size_type;
};

#endif //MULTIMAP_USE_COLLECTION_ITERATOR_H
