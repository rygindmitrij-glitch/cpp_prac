#pragma once

class DynamicArray
{
private:
    int size_ = 0;
    int* data_ = 0;
public:
    DynamicArray(int size);

    void printsize ();

    ~DynamicArray();

    void printValues ();

    void set (int i, int value);

    int get(int i);

    DynamicArray (const DynamicArray& other);

    void add(int value);

    void add(const DynamicArray& other);

    void sub(const DynamicArray& other);
};