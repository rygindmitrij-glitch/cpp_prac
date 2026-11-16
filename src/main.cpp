#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <string>
using namespace std;

int main () {
    DynamicArray<int> arr(4);
    arr.printValues();
    DynamicArray<int> copy(arr);
    arr.set (2,100);
    arr.printValues();
    DynamicArray<int> vtoroy(2);
    vtoroy.set (1,100);
    vtoroy.set (0,100);
    arr.sub(vtoroy);
    arr.printValues();
    arr.add(vtoroy);
    arr.printValues();
    copy.printValues();
    cout << arr.get(2) << "\n";
    arr.add(99);
    arr.printsize();
    arr.printValues();

    try {
        arr.get(99);
    } catch (const out_of_range& error){
        cout << error.what() << "\n";
    }

    try{
        arr.set(1,101);
    } catch (const invalid_argument& error){
        cout << error.what() << "\n";
    }

    try{
        throw bad_alloc{};
    } catch (const bad_alloc& error){
        cout << error.what() << "\n";
    }

    DynamicArray<string> words(2);
    words.set(0, "привет");
    words.set(1, "мир");
    words.printValues();
    cout << words << "\n";

    DynamicArray<double> A(2);
    DynamicArray<double> B(2);
    A.set(0, 3.0);
    A.set(1, 4.0);
    cout << A.distance(B) << "\n";
    DynamicArray<double> C(1);

    try{
        A.distance(C);
    } catch (const invalid_argument& error){
        cout << error.what() << "\n";
    }

    try{
        words.distance(words);
    } catch (const bad_typeid& error){
        cout << error.what() << "\n";
    }

}