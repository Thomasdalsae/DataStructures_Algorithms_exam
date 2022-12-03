#include "Sorters.h"
#include "DynamicArray.h"

using namespace std;



int main(int argc, char* argv[])
{
     DynamicArray<int> Array = {0}; // initialize array with list.
    DynamicArray<int> LargeArray{};
    cout << "Testing array methods: " << endl;
    cout << "Starting array: " << Array << endl;
    cout << "Has memory allocated for " << Array.GetCapacity() << " number of element(s)." << endl;
    cout << "Currently contains " << Array.GetSize() << " number of element(s)." << endl << endl;

    // appending: 
    cout << "Appending '11' to end of array: " << endl;
    Array.Append(11);
    cout << "current Array: " << Array << endl;
    cout << "Has memory allocated for " << Array.GetCapacity() << " number of element(s)." << endl;
    cout << "Currently contains " << Array.GetSize() << " number of element(s)." << endl << endl;

    // inserting:
    cout << "Inserting '-11' at index '0': " << endl;
    Array.Insert(0, -11);
    cout << "current Array: " << Array << endl;
    cout << "Has memory allocated for " << Array.GetCapacity() << " number of element(s)." << endl;
    cout << "Currently contains " << Array.GetSize() << " number of element(s)." << endl << endl;

    // expanding:
    cout << "Expanding capacity of array to 32 elements: " << endl;
    Array.Expand(32);
    cout << "current Array: " << Array << endl;
    cout << "Has memory allocated for " << Array.GetCapacity() << " number of element(s)." << endl;
    cout << "Currently contains " << Array.GetSize() << " number of element(s)." << endl << endl;

    // deleting:
    cout << "Deleting element at index '1'" << endl;
    cout << "Removed element was '" << Array.Remove(1) << "'" << endl;
    cout << "current Array: " << Array << endl;
    cout << "Has memory allocated for " << Array.GetCapacity() << " number of element(s)." << endl;
    cout << "Currently contains " << Array.GetSize() << " number of element(s)." << endl << endl;

    // Creating new array to test binary and linear search:
    Array = {14, 6, 16, 3, 13, 20, 18, 1, 10, 5, 10, 3, 17, 2, 12, 4, 19, 7, 15, 8, 7, 11};
    DynamicArray<int> TestArray = Array;

    cout << "Linear search for: 8 in array:" << endl;
    cout << " 8 is at index: " << TestArray.Find(8) << endl;
    cout << "current Array: " << TestArray << endl << endl;

    cout << "Binary search of sorted array: " << endl;
    Sorters::QuickSort(TestArray);
    cout << " 8 is at index: " << TestArray.Find(8, false) << endl;
    cout << "current Array: " << TestArray << endl << endl;

    //Creating a Large test Array for testing
    LargeArray.Expand(1000);
    for (int i = 0; i < 1000; i++)
    {
        LargeArray.Append(rand() % 800 - 200);
    }

    
    Array = {14, 6, 16, 3, 13, 20, 18, 1, 10, 5, 10, 3, 17, 2, 12, 4, 19, 7, 15, 8, 7, 11};
  TestArray = Array;
    //Creating a Large test Array for testing
    LargeArray.Expand(1000);
    for (int i = 0; i < 1000; i++)
    {
        LargeArray.Append(rand() % 800 - 200);
    }
 
    cout << "Unsorted: " << TestArray << endl;
    Sorters::SelectionSort(TestArray);
    cout << "Sorted: " << TestArray << endl;
    cout << "Currently contains " << TestArray.GetSize() << " number of element(s)." << endl;
    return 0;
}

