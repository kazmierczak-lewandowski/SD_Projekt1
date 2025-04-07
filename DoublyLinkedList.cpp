//
// Created by piotr on 01.04.25.
//

#include "DoublyLinkedList.hpp"

#include <ncurses.h>

void DoublyLinkedList::add(int element, const long index) {
  auto newNode = std::make_unique<Node>(element);
  if (index == 0) {
    newNode->next = std::move(head);
    head = std::move(newNode);
    if (isEmpty()) {
      tail = head.get();
    } else {
      head->next->prev = head.get();
    }
    increaseSize();
    return;
  }
  if (index == getSize()) {
    add(element);
    return;
  }
  auto current = head.get();
  for (long i = 0; i < index - 1; i++) {
    current = current->next.get();
  }
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
  auto current = head.get();
  long index = 0;
  while (current != nullptr) {
    if (current->data == element)
      return index;
    current = current->next.get();
    index++;
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

void DoublyLinkedList::remove(const long index) {
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
  auto current = head.get();
  for (long i = 0; i < index - 1; i++) {
    current = current->next.get();
  }
  current->next->next->prev = current;
  current->next = std::move(current->next->next);
  if (index == getSize() - 1) {
    tail = current;
  }
  decreaseSize();
}