//
// Created by piotr on 01.04.25.
//

#include "LinkedList.hpp"


void LinkedList::add(int element, long index) {
  auto newNode = std::make_unique<Node>(element);
  if (index == 0) {
    newNode->next = std::move(head);
    head = std::move(newNode);
    if (size == 0) {
      tail = head.get();
    }
  }
  else {
    Node* current = head.get();
    for (long i = 0; i<index-1; i++) {
      current = current->next.get();
    }
    newNode->next = std::move(current->next);
    current->next = std::move(newNode);
    if (index == size) {
      tail = current->next.get();
    }
  }
  size++;
}

void LinkedList::clear() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}
long LinkedList::get(int element) const {
  const Node* current = head.get();
  long index = 0;
  while (current != nullptr) {
    if (current->data == element) return index;
    current = current->next.get();
    index ++;
  }
  return -1;
}
void LinkedList::print() const {
  const Node* current = head.get();
  std::cout << '[';
  while (current != nullptr) {
    std::cout << current->data;
    current = current->next.get();
    if (current != nullptr) {
      std::cout << ", ";
    }
  }
  std::cout << ']' << std::endl;
}
void LinkedList::remove(long index) {
  if (index == 0) {
    head = std::move(head->next);
    if (size == 1) {
      tail = nullptr;
    }
  } else {
    Node* current = head.get();
    for (long i = 0; i < index - 1; ++i) {
      current = current->next.get();
    }
    current->next = std::move(current->next->next);
    if (index == size - 1) {
      tail = current;
    }
  }
  --size;
}
LinkedList::LinkedList() = default;