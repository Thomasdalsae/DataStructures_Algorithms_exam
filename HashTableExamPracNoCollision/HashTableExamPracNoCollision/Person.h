#pragma once
#define N_A_PERSON "00ffffffffffff"
template <typename T>
class Person
{
public:
    T Data{};
    std::string Name;
    int age;
    float money;
 
    // Next ptr for linked list
    Person* Next = nullptr;
};