//
// Created by kazik on 3/31/25.
//

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>
#include <memory>

#include "Collection.hpp"

class ArrayList final : private Collection {
 private:
  long capacity;
  long size = 0L;
  std::unique_ptr<int[]> elements;
  void ensureCapacity();
  void grow();

 public:
  static constexpr long DEFAULT_CAPACITY = 10;

  explicit ArrayList(int capacity = DEFAULT_CAPACITY);
  void print() const override;
  void add(int element) override;
  void remove(long index) override;
  void clear() override;
  [[nodiscard]] bool isEmpty() const override { return size == 0; }
  [[nodiscard]] int getFirst() const override { return elements[0]; }
  [[nodiscard]] int getLast() const override { return elements[size - 1]; }
  [[nodiscard]] long get(int element) const override;
  [[nodiscard]] long getSize() const override { return size; }
};

#endif  // ARRAYLIST_HPP
