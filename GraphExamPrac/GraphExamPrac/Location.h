#pragma once
#include <iostream>

using namespace std;


class Location
{
public:
int key;
    char name;
    Location* next;
    bool wasVisited;
    float x;
    float y;

    //Operator overload
    bool operator!=(const Location& rhd)
    {
        if (this->key != rhd.key)return true;
        else return false;
    }
    bool operator<(const Location& rhd)
    {
        if (this->key < rhd.key)return true;
        else return false;
    }
    bool operator==(const Location& rhd)
    {
        if (this->key == rhd.key)return true;
        else return false;
    }
    bool operator>(const Location& rhd)
    {
        if (this->key > rhd.key)return true;
        else return false;
    }
   

    void DisplayL()
    {
        cout<< "[ "<< name <<" ]"<< endl;
    }
    Location(int key,char name)
    {
        this->key = key;
        this->name=name;
        x = 0;
        y = 0;
    }
    Location(int key,char name,float x, float y)
    {
        this->key = key;
        this->name=name;
        this->x;
        this->y;
    }

    
    
};
