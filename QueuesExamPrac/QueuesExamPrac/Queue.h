
#include <iostream>
#include <ostream>

using namespace std;
template <typename T>

class Queue 
{
public:
 
private:
    int count;
    T* data;
    int front;
    int rear;
    int size;
    
public:
    Queue(T size)
    {
        this->size = size;
        data = new T[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    T PeakFront()
    {
     return data[front];   
    }
    bool IsEmpty()
    {
        if (count = 0)
        {
            return true;
        }
        else
        {

            return false ;
        }
    }
    bool IsFull()
    {
        if(count == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    T Size()
    {
    
        return this->size;
    }
    void Insert(T item)
    {
        if(rear == size -1)
        {
            rear = -1;
        }
        rear++;
        data[rear] = item;
        count++;
    }
    void RemoveFront()
    {
        if (front == -1 || front > rear)
        {
           cout << "queue underflow ";
            return;
        }
        else
        {
           cout << "Element deleted from queue is :" << data[front] << endl;
            front++;
        }
    }
    void RemoveEnd()
    {
        if (front == -1 || front > rear)
        {
            cout << "queue underflow ";
            return;
        }
        else
        {
            cout << "Element deleted from queue is :" << data[rear] << endl;
            rear--;
        }  
    }
    void Display()
    {
       
        if (front == -1){cout << "Queue is empty " << endl;}
        else
        {
            cout << " Queue elements are : " << endl;
            for (int i = front; i <= rear; ++i)
            {
                cout << data[i] << " " ;
                
            }
            cout << endl;
        }
    }
    
};
