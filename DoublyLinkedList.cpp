//
// Created by piotr on 06.04.25.
//

#include "DoublyLinkedList.hpp"
#include <ncurses.h>

void DoublyLinkedList::add(int element, const long index) {
  auto newNode = std::make_shared<Node>(element);
  if (index == 0) {
    newNode->next = head;
    head->previous = newNode;
    head = std::move(newNode);
    if (isEmpty()) {
      tail = head;
    }
    increaseSize();
    return;
  }
  std::shared_ptr<Node> current = head;
  for (long i = 0; i < index - 1; i++) {
    current = current->next;
  }
  current->next->previous = newNode;
  newNode->next = std::move(current->next);
  newNode->previous = current;
  current->next = std::move(newNode);
  if (index == getSize()) {
    tail = current->next;
  }
  increaseSize();
}

void DoublyLinkedList::add(int element) {
  auto newNode = std::make_shared<Node>(element);
  if (isEmpty()) {
    newNode->next = nullptr;
    newNode->previous = nullptr;
    head = std::move(newNode);
    tail = head;
    increaseSize();
    return;
  }
  newNode->previous = tail;
  newNode->next = nullptr;
  tail->next = newNode;
  tail = std::move(newNode);
  increaseSize();
}
void DoublyLinkedList::print() const {
  ::clear();
  std::shared_ptr<Node> current = head;
  std::string res = "[";
  while (current != nullptr) {
    res += std::to_string(current->data);
    current = current->next;
    if (current != nullptr) {
      res += ", ";
    }
  }
  res += "]";
  printw("%s", res.c_str());
}
void DoublyLinkedList::clear() {
  //a
}
long DoublyLinkedList::get(int element) const {
  //b
  return element;
}
void DoublyLinkedList::remove(long index) {
  //c
}


