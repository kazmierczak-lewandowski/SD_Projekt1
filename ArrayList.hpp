//
// Created by kazik on 3/31/25.
//

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>
#include <memory>

class ArrayList {
 private:
  long capacity;
  long size = 0L;
  std::unique_ptr<int[]> elements;
  void ensureCapacity();
  void grow();

 public:
  static constexpr long DEFAULT_CAPACITY = 10;

  explicit ArrayList(int capacity = DEFAULT_CAPACITY);
  void print() const;
  void add(int element);
  void removeIndex(long index);
  void removeElement(int element);
  void clear() { size = 0; }
  [[nodiscard]] bool isEmpty() const { return size == 0; }
  [[nodiscard]] int getFirst() const { return elements[0]; }
  [[nodiscard]] int getLast() const { return elements[size - 1]; }
  [[nodiscard]] int get(const long index) const { return elements[index]; }
  [[nodiscard]] long indexOf(int element) const;
  [[nodiscard]] long getSize() const { return size; }
};

#endif  // ARRAYLIST_HPP
