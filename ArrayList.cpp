//
// Created by kazik on 3/31/25.
//

#include "ArrayList.hpp"

void ArrayList::ensureCapacity() {
  if (capacity == size + 1) {
    grow();
  }
}
void ArrayList::grow() {
  auto temp = std::make_unique<int[]>(size * 2);
  for (long i = 0; i < size; i++) {
    temp[i] = elements[i];
  }
  elements = std::move(temp);
  capacity = size * 2;
}
ArrayList::ArrayList(const int capacity) : capacity(capacity) {
  if (capacity <= 0)
    throw std::invalid_argument("capacity must be greater than 0");
  elements = std::make_unique<int[]>(capacity);
}
void ArrayList::print() const {
  std::cout << '[';
  for (long i = 0; i < size; i++) {
    std::cout << elements[i];
    if (i != size - 1) {
      std::cout << ", ";
    } else
      std::cout << ']';
  }
  std::cout << std::endl;
}
void ArrayList::add(const int element, const long index) {
  ensureCapacity();
  for (long i = size; i > index; i--) {
      elements[i] = elements[i - 1];
  }
  elements[index] = element;
  size++;
}
void ArrayList::remove(const long index) {
  for (long i = index; i < size - 1; i++) {
    elements[i] = elements[i + 1];
  }
  size--;
}
void ArrayList::clear() {
  size = 0;
  capacity = DEFAULT_CAPACITY;
}
long ArrayList::get(const int element) const {
  for (long i = 0; i < size; i++) {
    if (elements[i] == element) {
      return i;
    }
  }
  return -1;
}