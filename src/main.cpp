#include "DynamicArray.h"
#include <iostream>
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
}