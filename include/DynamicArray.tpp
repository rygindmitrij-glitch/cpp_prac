#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <cmath>
#include <typeinfo>
using namespace std;

template <typename T>

DynamicArray<T>:: DynamicArray(int size){
        size_ = size;
        data_ = new T[size_]{};
    }

    template <typename T>
    double DynamicArray<T>:: distance(const DynamicArray<T>& other) const{
        if constexpr (!is_arithmetic_v<T>){
            throw bad_typeid();
        } else{
            if (size_ != other.size_){
                throw invalid_argument("размеры массивов разные");
            }
            double sum = 0.0;

            for (int i = 0; i < size_; i++){
                double difference = static_cast<double>(data_[i]) - static_cast<double>(other.data_[i]);

                sum += difference * difference;
            }
            return sqrt(sum);
        }
    }

    template <typename T>
    void DynamicArray<T>:: printsize (){
        cout << size_ << "\n";
    }
    template <typename T>
    DynamicArray<T>:: ~DynamicArray(){
        delete[] data_;
    }

    template <typename T>
    void DynamicArray<T>:: printValues (){
        for (int i = 0; i < size_; i++){
            cout << data_[i]<<" ";
        }
        cout << "\n";
    }

    template <typename T>
    void DynamicArray<T>:: set (int i, T value){
        if (i < 0 || i >= size_)
        {
            throw out_of_range("такого индекса в массиве нет");
        }
        if constexpr (is_integral_v<T>) {
            if (value > 100 || value < -100){
                throw invalid_argument("такое значение не может быть записано в массив");
            }
        }
        data_[i] = value;
    }

    template <typename T>
    T DynamicArray<T>:: get(int i){
        if (i < 0 || i >= size_)
        {
            throw out_of_range("такого индекса в массиве нет");
        }
        return data_[i];
    }

    template <typename T>
    DynamicArray<T>:: DynamicArray (const DynamicArray<T>& other){
        size_ =  other.size_;
        data_ = new T[size_]{};
        for (int i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }

    template <typename T>
    void DynamicArray<T>:: add(T value){
        if constexpr (is_integral_v<T>) {
            if (value > 100 || value < -100){
                throw invalid_argument("такое значение не может быть записано в массив");
            }
        }
        T* dataVREM = 0;
        dataVREM = new T[size_ + 1]{};
        for (int i = 0; i < size_; i++)
        {
            dataVREM[i] = data_[i];

        }
        dataVREM[size_] = value;
        delete[] data_;
        data_ = dataVREM;
        size_++;
    }

    template <typename T>
    void DynamicArray<T>:: add(const DynamicArray<T>& other){
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

    template <typename T>
    void DynamicArray<T>:: sub(const DynamicArray<T>& other){
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