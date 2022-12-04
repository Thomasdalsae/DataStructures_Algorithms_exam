#pragma once
#define N_A_PERSON "00ffffffffffff"

template <typename D, typename K>
class Person
{
public:
    K key;
    D Data{};
    std::string Name;
    int age;
    float money;

    
    // Next ptr for linked list
    Person* Next = nullptr;
};