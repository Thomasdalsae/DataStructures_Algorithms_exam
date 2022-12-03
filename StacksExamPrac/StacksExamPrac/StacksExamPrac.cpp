#include "StackEP.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    StackEP* s = new StackEP(4);
    s->Push(5);
    cout << s->top << endl;
    s->Push(15);
    cout << s->top << endl;
    s->Push(55);
    cout << s->top << endl;
    s->Push(500);
    cout << s->top << endl;

    if (s->IsFull()) { cout << "full"; }
    else { cout << "not full"; }
    cout << endl;

    cout << s->top << endl;

    while (s->IsEmpty() == false)
    {
        cout << s->Pop() << endl;
    }
    
    cout << s->top << endl;
    
    if (s->IsFull()) { cout << "full"; }
    else { cout << "not full"; }
    cout << endl;

    return 0;
}
