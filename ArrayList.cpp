//
// Created by kazik on 3/31/25.
//

#include "ArrayList.hpp"

void ArrayList::ensureCapacity() {
  if (capacity == getSize() + 1) {
    grow();
  }
}
void ArrayList::grow() {
  auto temp = std::make_unique<int[]>(getSize() * 2);
  for (long i = 0; i < getSize(); i++) {
    temp[i] = elements[i];
  }
  elements = std::move(temp);
  capacity = getSize() * 2;
}
ArrayList::ArrayList(const int capacity) : capacity(capacity) {
  if (capacity <= 0)
    throw std::invalid_argument("capacity must be greater than 0");
  elements = std::make_unique<int[]>(capacity);
}
void ArrayList::print() const {
  std::cout << '[';
  for (long i = 0; i < getSize(); i++) {
    std::cout << elements[i] << ", ";
  }
  std::cout << ']' << std::endl;
}
void ArrayList::add(const int element, const long index) {
  ensureCapacity();
  for (long i = getSize(); i > index; i--) {
    elements[i] = elements[i - 1];
  }
  elements[index] = element;
  increaseSize();
}
void ArrayList::add(const int element) {
  ensureCapacity();
  elements[getSize()] = element;
  increaseSize();
}

void ArrayList::remove(const long index) {
  for (long i = index; i < getSize() - 1; i++) {
    elements[i] = elements[i + 1];
  }
  decreaseSize();
}
void ArrayList::clear() {
  clearSize();
  capacity = DEFAULT_CAPACITY;
}
long ArrayList::get(const int element) const {
  for (long i = 0; i < getSize(); i++) {
    if (elements[i] == element) {
      return i;
    }
  }
  return -1;
}