#pragma once

class StackEP
{
private:
    int maxSize;
    int* stackData;
    
public:
    int top;
    StackEP(int maxSize)
    {
        this->maxSize = maxSize;
        stackData = new int [maxSize];
        top = -1;
    }
    void Push(int value)
    {
        top++;
        stackData[top] = value;
    }
    int Pop()
    {
        int itemToReturn = stackData[top];
        top--;
        return itemToReturn;
    }
    int Peek()
    {
        return stackData[top];
    }

    bool  IsEmpty()
    {
        if(top == -1)return true;
        else return false;
    }

    bool IsFull()
    {
        if (top == (maxSize-1))
            return true;
        else
            return false;
    }
};
