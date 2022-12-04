#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
using namespace std;

#define MAX_NAME 256
#define TABLE_SIZE 10


template <typename T>
class Hash_Table 
{
private:

public:
    Person<T>* hash_table[TABLE_SIZE];
    //Person<T>* HashTable[TABLE_SIZE];
    //Getters
    size_t GetLength(const std::string s) { return s.size(); }

    //Functions
    size_t hashFunc(string name); // Makes a hash from the name
    void init_hash_table(); 
    void print_table();
    bool hash_table_insert(Person<T> p);
    Person<T> hash_table_lookup(string name);
    void hash_table_delete(string name);

};
    //OVERLOADDDDDDDDDDDDS
    // template <typename T>
    // T GetLength(const char* s){return strlen(s);}



    template <typename T>
    size_t Hash_Table<T>::hashFunc(string name)
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



 template <typename T>
    void Hash_Table<T>::init_hash_table()
    {
        {
            for (int i = 0; i < TABLE_SIZE; ++i)
            {
                hash_table[i] = nullptr;
            }
            //Table is empty
        }
    }
   

    
template <typename T>
    void Hash_Table<T>::print_table()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (hash_table[i] != nullptr)
            {
                cout << i << "  --- " ;

                Person<T>* tmp = hash_table[i];

                while (tmp != nullptr)
                {
                    cout <<"[" <<tmp->Name <<"]"<<" <-> ";
                    tmp = tmp->Next;
                }
                cout << endl;
            }
        }
        cout << "End" << endl;
    }

template <typename T>
bool Hash_Table<T>::hash_table_insert(Person<T> p)
    {
        // copy constructor if passing something of same type it will contain same information.
        // if copied contains next/prev it will also copy that, if deleting one of them it might try to delete the thing it pointing to.
        Person<T>* tmp = new Person<T>(p);
    
        if (tmp == nullptr)return false;
        int index = hashFunc(tmp->Name);
        tmp->Next = hash_table[index];
        hash_table[index] = tmp;
    
        return true;
    }

    //Find a person in the table by their name
    template <typename T>
    Person<T> Hash_Table<T>::hash_table_lookup(string name)
    {

        int index = hashFunc(name);
    
        Person<T>* tmp = hash_table[index];
        
        while (tmp != nullptr && tmp->Name != name)
        {
            tmp = tmp->Next;
          
        }
        if (tmp == nullptr)
        {
           
            // way of securing data, returning a dummy to make people unable to manipulate the Hashtable Linked list.
            Person<T> REEE = Person<T>();
            REEE.Name = N_A_PERSON;
            return REEE;
        }
      
        return *tmp;
    
    }

    template <typename T>
    void Hash_Table<T>::hash_table_delete(string name)
    {
        
        int index = hashFunc(name);//Start index will be the hash value of the name. quicker to find 
        Person<T>* tmp = hash_table[index]; //makes a temp  of the contents at the given index
        Person<T>* prev = nullptr;
        //looping while trying to find a match in the hashtable.
        while (tmp != nullptr && tmp->Name != name)
        {
            prev = tmp;
            tmp = tmp->Next;
        }
        if (tmp == nullptr) // if tmp is null just give user message that there is noone with that name
        {
            cout << "Noone with the name of : " << name << " is in the hash table" << endl;
            return ;
        }
        if (prev == nullptr) // if prev equals nullptr, there is head in the linked list on hashtable
        {
            cout << "Deleting head node which contain name : " << name << " from the hash table" << endl;
            // deleteing the head
            hash_table[index] = tmp->Next;
        }
        else // if temp is not a null or prev is not a nullptr there must be a match in the hashtable. after finding it. delete
        {
            cout << "Deleting : " << name << " from the hash table" << endl;
            prev->Next = tmp->Next;
        }
        return;
    }
