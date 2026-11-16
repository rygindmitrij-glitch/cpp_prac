#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>
using namespace std;

int main () {
    DynamicArray arr(4);
    arr.printValues();
    DynamicArray copy(arr);
    arr.set (2,100);
    arr.printValues();
    DynamicArray vtoroy(2);
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
}