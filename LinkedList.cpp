//
// Created by piotr on 01.04.25.
//

#include "LinkedList.hpp"

#include <ncurses.h>

void LinkedList::add(int element, const long index) {
  auto newNode = std::make_unique<Node>(element);
  if (index == 0) {
    newNode->next = std::move(head);
    head = std::move(newNode);
    if (isEmpty()) {
      tail = head.get();
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
  newNode->next = std::move(current->next);
  current->next = std::move(newNode);
  increaseSize();
}

void LinkedList::add(int element) {
  auto newNode = std::make_unique<Node>(element);
  if (isEmpty()) {
    head = std::move(newNode);
    tail = head.get();
    increaseSize();
    return;
  }
  tail->next = std::move(newNode);
  tail = tail->next.get();
  increaseSize();
}

void LinkedList::clear() {
  while (head) {
    head = std::move(head->next);
  }
  tail = nullptr;
  clearSize();
}

long LinkedList::get(const int element) const {
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

LinkedList::~LinkedList() {
  clear();
}

void LinkedList::print() const {
  auto current = head.get();
  std::cout << '[';
  ::clear();
  std::shared_ptr<Node> current = head;
  std::string res = "[";
  while (current != nullptr) {
    std::cout << current->data;
    current = current->next.get();
    res += std::to_string(current->data);
    current = current->next;
    if (current != nullptr) {
      res += ", ";
    }
  }
  res += "]";
  printw("%s", res.c_str());
}

void LinkedList::remove(const long index) {
  if (index == 0) {
    head = std::move(head->next);
    if (getSize() == 1) {
      tail = nullptr;
    }
    decreaseSize();
    return;
  }
  auto current = head.get();
  for (long i = 0; i < index - 1; i++) {
    current = current->next.get();
  }
  current->next = std::move(current->next->next);
  if (index == getSize() - 1) {
    tail = current;
  }
  decreaseSize();
}