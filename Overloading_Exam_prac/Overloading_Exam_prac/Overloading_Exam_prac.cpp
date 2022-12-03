#include "DaysOverLoad.h"
#include "Vector2D.h"
#include "Entity.h"
#include <iostream>
#include <string>
using namespace std;


void entityTest()
{
    entity<int> en1(10);
    entity<int> en2(23);
    ++en1;
    cout << en1.size;
    --en1;
    cout << en1.size;

    
     // if(en1 < en2)
     // {
     //     cout << "en1 less than en2";
     // }

   
 
}

void UnaryOperatorOverloadDays()
{
 Day myDay = tue;
    ++myDay;
    cout << myDay << endl; //Displays 3
}


void UnaryOperatorOverload()
{
    Vector2D<int> v1(10,15);
    Vector2D<int> v2(6,9);
    Vector2D<int> v3 = v1 + v2;
    cout << "V1 :x: " << v1.x << " y: " << v1.y << endl;
    v2 = !v1;
    cout << "V2 :x: " << v2.x << " y: " << v2.y << endl;
    cout  << "x:" << v3.x << " y" << v3.y << endl;
}

int main(int argc, char* argv[])
{
    entityTest();
    //UnaryOperatorOverload();
    //UnaryOperatorOverloadDays<int>();
    return 0;
}
