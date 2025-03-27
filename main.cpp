#include <iostream>

#include "ArrayList.h"

int main() {
    ArrayList<int> array;
    array.add(1);
    array.add(2);
    array.add(3);
    array.print();
    array.removeElement(1);
    array.print();
    return 0;
}
