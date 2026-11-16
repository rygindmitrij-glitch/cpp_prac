#pragma once
#include <ostream>
using namespace std;
template <typename T>

class DynamicArray
{
private:
    int size_ = 0;
    T* data_ = 0;
public:
    friend ostream& operator<<(ostream& os, const DynamicArray& arr) {
        for (int i = 0; i < arr.size_; i++)
        {
            os << arr.data_[i] << " ";
        }
        return os;
    } 

    double distance(const DynamicArray& other) const;

    DynamicArray(int size);

    void printsize ();

    ~DynamicArray();

    void printValues ();

    void set (int i, T value);

    T get(int i);

    DynamicArray (const DynamicArray& other);

    void add(T value);

    void add(const DynamicArray& other);

    void sub(const DynamicArray& other);
};
#include "DynamicArray.tpp"