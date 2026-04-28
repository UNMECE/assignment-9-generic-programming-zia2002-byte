#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class GenericArray
{
private:
    T* data;
    int length;

public:
    GenericArray()
    {
        data = nullptr;
        length = 0;
    }

    ~GenericArray()
    {
        delete[] data;
    }

    void addElement(T value)
    {
        T* newData = new T[length + 1];

        for(int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }

        newData[length] = value;

        delete[] data;
        data = newData;
        length++;
    }

    T at(int index)
    {
        if(index < 0 || index >= length)
        {
            cout << "Index out of bounds" << endl;
            return T();
        }

        return data[index];
    }

    int size()
    {
        return length;
    }

    T sum()
    {
        T total = 0;

        for(int i = 0; i < length; i++)
        {
            total += data[i];
        }

        return total;
    }

    T max()
    {
        T largest = data[0];

        for(int i = 1; i < length; i++)
        {
            if(data[i] > largest)
                largest = data[i];
        }

        return largest;
    }

    T min()
    {
        T smallest = data[0];

        for(int i = 1; i < length; i++)
        {
            if(data[i] < smallest)
                smallest = data[i];
        }

        return smallest;
    }

    T* slice(int begin, int end)
    {
        if(begin < 0 || end >= length || begin > end)
        {
            cout << "Invalid slice bounds" << endl;
            return nullptr;
        }

        int newSize = end - begin + 1;
        T* newArray = new T[newSize];

        for(int i = 0; i < newSize; i++)
        {
            newArray[i] = data[begin + i];
        }

        return newArray;
    }
};

#endif
