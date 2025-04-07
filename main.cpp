#include <iostream>
#include "ArrayList.hpp"
#include "LinkedList.hpp"

void testArrayList() {
  ArrayList arrayList;
  arrayList.add(1);
  arrayList.add(2);
  arrayList.add(3, 1);
  arrayList.print(); // Expected output: [1, 3, 2]

  arrayList.remove(1);
  arrayList.print(); // Expected output: [1, 2]

  std::cout << "First element: " << arrayList.getFirst() << std::endl; // Expected output: 1
  std::cout << "Last element: " << arrayList.getLast() << std::endl; // Expected output: 2
  std::cout << "Index of element 2: " << arrayList.get(2) << std::endl; // Expected output: 1

  arrayList.clear();
  arrayList.print(); // Expected output: []
}

void testLinkedList() {
  LinkedList linkedList;
  linkedList.add(1);
  linkedList.add(2);
  linkedList.add(3, 1);
  linkedList.print(); // Expected output: [1, 3, 2]

  linkedList.remove(1);
  linkedList.print(); // Expected output: [1, 2]

  std::cout << "First element: " << linkedList.getFirst() << std::endl; // Expected output: 1
  std::cout << "Last element: " << linkedList.getLast() << std::endl; // Expected output: 2
  std::cout << "Index of element 2: " << linkedList.get(2) << std::endl; // Expected output: 1

  linkedList.clear();
  linkedList.print(); // Expected output: []
}

int main() {
  std::cout << "Testing ArrayList:" << std::endl;
  testArrayList();

  std::cout << "Testing LinkedList:" << std::endl;
  testLinkedList();

  return 0;
}