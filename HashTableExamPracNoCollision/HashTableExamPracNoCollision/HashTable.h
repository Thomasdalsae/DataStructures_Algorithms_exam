#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Initializer.h"
#include "Node.h"
#include "assert.h"
#include "Person.h"
using namespace std;

#define MAX_NAME 256
#define TABLE_SIZE 10
#define SHOW_DEBUG


template <typename K>
int HashFunction(K key, const int& tableSize) {
    assert(std::is_arithmetic_v<K>);
    return static_cast<int>(key) % tableSize;
}

template <>
int HashFunction<std::string>(std::string key, const int& tableSize) {
    // if key is text, get sum of ascii values mod capacity
    size_t sum{};
    for (const char i : key) {
        sum += static_cast<size_t>(i);
    }
    return sum % tableSize;
}

template <>
int HashFunction<Person>(Person key, const int& tableSize) {
    // if key is text, get sum of ascii values mod capacity
    return key.Age & tableSize;
}

template <typename K, typename D>
class Hash_Table {
private:
public:
    Hash_Table() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            hash_table[i] = nullptr;
        }
    }


    Node<K, D>* hash_table[TABLE_SIZE];
    //Person<T>* HashTable[TABLE_SIZE];
    //Getters
    size_t GetLength(const std::string s) { return s.size(); }

    //Functions
    void Print();
    void Insert(K key, D data);
    D Lookup(K key);
    void Delete(D key);
    bool IsEmpty() const;
};

//OVERLOADDDDDDDDDDDDS
// template <typename T>
// T GetLength(const char* s){return strlen(s);}

template <typename K, typename D>
bool Hash_Table<K, D>::IsEmpty() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {

        Node<K, D>* bucket = hash_table[i];
        if (bucket != nullptr)
            return false;
    }

    return true;
}

/*
template<typename K, typename D>
    size_t Hash_Table<K , D>::hashFunc(string name)
    {
        int length = GetLength(name);

        // cout << "Length of Name : "<< length << endl;
        unsigned int hash_value = 0;
        for (int i = 0; i < length; ++i)
        {
            hash_value += name[i];
            hash_value = (hash_value * name[i]) % TABLE_SIZE;
        }
        return hash_value;
    }
    */

template <typename K, typename D>
void Hash_Table<K, D>::Print() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << i << ": ";
        if (hash_table[i] != nullptr) {
            Node<K, D>* tmp = hash_table[i];

            while (tmp != nullptr) {
                cout << "[" << tmp->Data;
                cout << "]" << " <-> ";
                tmp = tmp->Next;
            }
        }
        cout << endl;
    }
    cout << "End" << endl;
}

template <typename K, typename D>
void Hash_Table<K, D>::Insert(K key, D data) {
    // copy constructor if passing something of same type it will contain same information.
    // if copied contains next/prev it will also copy that, if deleting one of them it might try to delete the thing it pointing to.
    //Person<D>* tmp = new Person<D>(key);

    int index = HashFunction<K>(key,TABLE_SIZE);
    // check if we have collison
    if (hash_table[index] == nullptr) {
        Node<K, D>* Temp = new Node<K,D>(key, data);

        Temp->Next = hash_table[index];
        hash_table[index] = Temp;
        return;
    }

    // one or more items exists in this bucket
    Node<K, D>* probeNode = hash_table[index];
    while (probeNode != nullptr) {
        if (probeNode->Key == key) {
            // KEY COLLISION
            // SAME KEY INVALID
            probeNode->Data = data;
            std::cout << "WARNING: INSERTED WITH A KEY THAT ALLEREDY EXISTS, REPLACING DATA\n";
            return;
        }
        // this means we are at the last node, and that
        // we dont have a *Key* collision
        if (probeNode->Next == nullptr) {
            break;
        }
        probeNode = probeNode->Next;
    }
    // if we reach here, probeNode = LastNode in bucket
    probeNode->Next = new Node<K, D>(key, data);
    // if (tmp == nullptr)return false;
    // int index = HashFunction(tmp->Key);
    // tmp->Next = hash_table[index];
    // hash_table[index] = tmp;
    //
    // return true;
}

//Find a person in the table by their name
template <typename K, typename D>
D Hash_Table<K, D>::Lookup(K key) {

    int index = HashFunction(key, TABLE_SIZE);

    Node<K, D>* tmp = hash_table[index];

    // had collition
    while (tmp != nullptr && tmp->Key != key) {
        tmp = tmp->Next;

    }
    if (tmp == nullptr)
        return Initializer<D>().t;


    // if we reached end, we had a key match
    return tmp->Data;
}

template <typename D, typename K>
void Hash_Table<D, K>::Delete(K key) {

    int index = HashFunction(key, TABLE_SIZE); //Start index will be the hash value of the name. quicker to find 
    Node<K, D>* tmp = hash_table[index]; //makes a temp  of the contents at the given index
    Node<K, D>* prev = nullptr;
    //looping while trying to find a match in the hashtable.
    if (tmp == nullptr) {
#ifdef SHOW_DEBUG
        cout << "NO ITEMS IN BUCKET\n";
#endif
        return;
    }
    while (tmp != nullptr) {
        if (tmp->Key == key) {
            // found key want to remove
            if (prev == nullptr) { // if we are at first element
                hash_table[index] = tmp->Next;
            }
            else {
                prev->Next = tmp->Next;
            }
#ifdef SHOW_DEBUG
            cout << "KEY FOUND; DELETED KEY: " << tmp->Key << " DATA: " << tmp->Data << endl;
#endif
            delete tmp;
            return;
        }
        prev = tmp;
        tmp = tmp->Next;
    }
    // if we reach here, no key found, can safely return.
#ifdef SHOW_DEBUG
    cout << "NO KEY FOUND; DID NOT DELETE ANYTHING" << endl;
#endif
    return;


    // if (tmp == nullptr) // if tmp is null just give user message that there is noone with that name
    // {
    //     cout << "Noone with the name of : " << key << " is in the hash table" << endl;
    //     return;
    // }
    // if (prev == nullptr) // if prev equals nullptr, there is head in the linked list on hashtable
    // {
    //     cout << "Deleting head node which contain name : " << key << " from the hash table" << endl;
    //     // deleteing the head
    //     hash_table[index] = tmp->Next;
    // }
    // else
    // // if temp is not a null or prev is not a nullptr there must be a match in the hashtable. after finding it. delete
    // {
    //     cout << "Deleting : " << key << " from the hash table" << endl;
    //     prev->Next = tmp->Next;
    // }
}
