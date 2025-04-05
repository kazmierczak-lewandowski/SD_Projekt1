//
// Created by piotr on 01.04.25.
//

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <memory>
#include <iostream>

#include "Collection.hpp"

class LinkedList final : Collection{
private:
  struct Node {
    std::unique_ptr<Node> next = nullptr;
    int data;
    explicit Node(int value) : data(value) {}
  };
  long size = 0L;
  std::unique_ptr<Node> head = nullptr;
  Node* tail = nullptr;
public:
  explicit LinkedList();
  void print() const override;
  void add(int element, long index) override;
  void remove(long index) override;
  void clear() override;
  [[nodiscard]] bool isEmpty() const override { return size == 0; }
  [[nodiscard]] int getFirst() const override { return head->data; }
  [[nodiscard]] int getLast() const override { return tail->data; }
  [[nodiscard]] long get(int element) const override;
  [[nodiscard]] long getSize() const override { return size; }
};



#endif //LINKEDLIST_HPP
