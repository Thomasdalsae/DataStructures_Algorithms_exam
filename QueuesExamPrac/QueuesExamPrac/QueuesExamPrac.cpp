
#include <queue>

#include "Queue.h"

int main(int argc, char* argv[])
{
 
  Queue<int> TestArray(5);

    TestArray.Insert(2);
    TestArray.Insert(9);
    TestArray.Insert(1);
    TestArray.Insert(3);
    TestArray.Insert(72);
    TestArray.Insert(87);
    TestArray.Insert(12);
    TestArray.Insert(23);
    TestArray.Display();
    TestArray.RemoveFront();
    TestArray.Display();
    TestArray.RemoveEnd();
   TestArray.Display();
    TestArray.Insert(4);
    TestArray.Display();
     cout << "Front data is: " <<TestArray.PeakFront() << endl;
     cout << "Size of the array is: " <<TestArray.Size() << endl;
     if (TestArray.IsFull())
     {
         cout << "Array is full: " << endl;
     }
     else
     {
         cout << "array is not full: " << endl;
     }

    
    return 0;
}
