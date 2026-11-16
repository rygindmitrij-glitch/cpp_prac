#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray :: DynamicArray(int size){
        size_ = size;
        data_ = new int[size_]{};
    }

    void DynamicArray :: printsize (){
        cout << size_ << "\n";
    }
    DynamicArray :: ~DynamicArray(){
        delete[] data_;
    }

    void DynamicArray :: printValues (){
        for (int i = 0; i < size_; i++){
            cout << data_[i]<<" ";
        }
        cout << "\n";
    }

    void DynamicArray :: set (int i, int value){
        if (i < 0 || i >= size_)
        {
            cout << "такого индекса в массиве нет\n";
            return;
        }
        if (value > 100 || value < -100)
        {
            cout << "такое значение не может быть записано в массив\n";
            return;
        }
        
        data_[i] = value;
    }

    int DynamicArray :: get(int i){
        if (i < 0 || i >= size_)
        {
            cout << "такого индекса в массиве нет\n";
            return 0;
        }
        return data_[i];
    }

    DynamicArray :: DynamicArray (const DynamicArray& other){
        size_ =  other.size_;
        data_ = new int[size_]{};
        for (int i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }

    void DynamicArray ::  add(int value){
        if (value > 100 || value < -100)
        {
            cout << "такое значение не может быть записано в массив\n";
            return;
        }
        int* dataVREM = 0;
        dataVREM = new int[size_ + 1]{};
        for (int i = 0; i < size_; i++)
        {
            dataVREM[i] = data_[i];

        }
        dataVREM[size_] = value;
        delete[] data_;
        data_ = dataVREM;
        size_++;
    }

    void DynamicArray :: add(const DynamicArray& other){
        if (other.size_ > size_)
        {
            for (int i = 0; i < size_; i++)
            {
                data_[i] += other.data_[i];
            }
            
        } else {
            for (int i = 0; i < other.size_; i++)
            {
                data_[i] += other.data_[i];
            }
        }
        
    }

    void DynamicArray :: sub(const DynamicArray& other){
        if (other.size_ > size_)
        {
            for (int i = 0; i < size_; i++)
            {
                data_[i] -= other.data_[i];
            }
            
        } else {
            for (int i = 0; i < other.size_; i++)
            {
                data_[i] -= other.data_[i];
            }
        }
        
    }