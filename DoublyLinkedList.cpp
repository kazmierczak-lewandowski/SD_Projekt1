//
// Created by piotr on 01.04.25.
//

#include "DoublyLinkedList.hpp"

#include <ncurses.h>

void DoublyLinkedList::traverse(long& index, DoublyLinkedList::Node*& current) {
  bool const isFirstHalf = getSize() / 2 >= index;
  if (isFirstHalf)
    current = head.get();
  else {
    current = tail;
    index = getSize() - index - 1;
  }
  for (long i = 0; i < index - 1; i++) {
    if (isFirstHalf)
      current = current->next.get();
    else
      current = current->prev;
  }
  if (!isFirstHalf) current = current->prev->prev;
}
void DoublyLinkedList::add(int element, long index) {
  auto newNode = std::make_unique<Node>(element);
  if (index == 0) {
    newNode->next = std::move(head);
    head = std::move(newNode);
    if (isEmpty()) {
      tail = head.get();
    }
    else {
      head->next->prev = head.get();
    }
    increaseSize();
    return;
  }
  if (index == getSize()) {
    add(element);
    return;
  }
  Node *current = nullptr;
  traverse(index, current);
  newNode->prev = current;
  newNode->next = std::move(current->next);
  current->next = std::move(newNode);
  current->next->next->prev = current->next.get();
  if (index == getSize()) {
    tail = current->next.get();
  }
  increaseSize();
}

void DoublyLinkedList::add(int element) {
  auto newNode = std::make_unique<Node>(element);
  if (isEmpty()) {
    head = std::move(newNode);
    tail = head.get();
    increaseSize();
    return;
  }
  newNode->prev = tail;
  tail->next = std::move(newNode);
  tail = tail->next.get();
  increaseSize();
}

void DoublyLinkedList::clear() {
  while (head) {
    head = std::move(head->next);
  }
  tail = nullptr;
  clearSize();
}

long DoublyLinkedList::get(const int element) const {
  auto currentHead = head.get();
  auto currentTail = tail;
  for (long index = 0; currentHead != currentTail; index++) {
    if (currentHead->data == element) return index;
    if (currentTail->data == element) return getSize()-index-1;
    currentHead = currentHead->next.get();
    currentTail = currentTail->prev;
  }
  return -1;
}

DoublyLinkedList::~DoublyLinkedList() { clear(); }

void DoublyLinkedList::print() const {
  ::clear();
  auto current = head.get();
  std::string res = "[";
  while (current != nullptr) {
    res += std::to_string(current->data);
    current = current->next.get();
    if (current != nullptr) {
      res += ", ";
    }
  }
  res += "]";
  printw("%s", res.c_str());
}

void DoublyLinkedList::printBack() const {
  ::clear();
  auto current = tail;
  std::string res = "[";
  while (current != nullptr) {
    res += std::to_string(current->data);
    current = current->prev;
    if (current != nullptr) {
      res += ", ";
    }
  }
  res += "]";
  printw("%s", res.c_str());
}

void DoublyLinkedList::remove(long index) {
  if (index == 0) {
    head->next->prev = nullptr;
    head = std::move(head->next);
    if (getSize() == 1) {
      tail = nullptr;
    }
    decreaseSize();
    return;
  }
  if (index == getSize() - 1) {
    tail = tail->prev;
    tail->next = nullptr;
    return;
  }
  Node *current = nullptr;
  traverse(index, current);
  current->next->next->prev = current;
  current->next = std::move(current->next->next);
  if (index == getSize() - 1) {
    tail = current;
  }
  decreaseSize();
}