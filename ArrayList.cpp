//
// Created by kazik on 3/31/25.
//

#include "ArrayList.hpp"
#include <ncurses.h>
void ArrayList::ensureCapacity() {
  if (capacity == getSize()) {
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
  ::clear();
  std::string result = "[";
  for (long i = 0; i < getSize(); i++) {
    result += std::to_string(elements[i]);
    if (i != getSize() - 1) {
      result += ", ";
    }
  }
  result += "]";
  printw("%s", result.c_str());
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
  long reverse = getSize()-1;
  for (long i = 0; i < reverse; i++) {
    if (elements[i] == element) {
      return i;
    }
    if (elements[reverse] == element) {
      return reverse;
    }
    reverse--;
  }
  return -1;
}