//
// Created by kazik on 4/4/25.
//

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Collection.hpp"

class DoublyLinkedList final : public Collection {
public:
  void print() const override;
  void add(int element) override;
  void remove(long index) override;
  void clear() override;
  [[nodiscard]] bool isEmpty() const override;
  [[nodiscard]] int getFirst() const override;
  [[nodiscard]] int getLast() const override;
  [[nodiscard]] long get(int element) const override;
  [[nodiscard]] long getSize() const override;
};



#endif //DOUBLYLINKEDLIST_HPP
