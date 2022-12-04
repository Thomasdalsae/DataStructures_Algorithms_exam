#pragma once
#include <string>
#define N_A_PERSON "00ffffffffffff"

template <typename K, typename D>
class Node {
public:
    K Key{};
    D Data{};

    Node(K key, D data) {
        Key = key;
        Data = data;
    }

    // Next ptr for linked list
    Node* Next = nullptr;
};
