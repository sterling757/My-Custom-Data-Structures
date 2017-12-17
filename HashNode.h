/*
 * Owner: Kyra
 *
 * References:
 *  General outline: https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
 *
 */

#ifndef HASHNODE_H
#define HASHNODE_H

#include <vector>

template <class K, class V>
class HashNode {
public:
    HashNode();
    HashNode(K&, V&);
    HashNode(K&, vector<V>&);

    template <class U, class Y> friend class HashTable;
private:
    K key;
    std::vector<V> values;

    HashNode* next;
};

template <class K, class V>
HashNode<K,V>::HashNode(K& setKey, V& setValue) {
    key = setKey;
    values.push_back(setValue);
    next = nullptr;
}

template <class K, class V>
HashNode<K,V>::HashNode(K& setKey, vector<V>& setVector) {
    key = setKey;
    values = setVector;
    next = nullptr;
}

#endif // HASHNODE_H
