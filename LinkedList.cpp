//
// Created by piotr on 01.04.25.
//

#include "LinkedList.hpp"

#include <ncurses.h>

void LinkedList::add(int element, const long index) {
  auto newNode = std::make_shared<Node>(element);
  if (index == 0) {
    newNode->next = std::move(head);
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
  newNode->next = std::move(current->next);
  current->next = std::move(newNode);
  if (index == getSize()) {
    tail = current->next;
  }
  increaseSize();
}
void LinkedList::add(int element) {
  auto newNode = std::make_shared<Node>(element);
  if (isEmpty()) {
    newNode->next = nullptr;
    head = std::move(newNode);
    tail = head;
    increaseSize();
    return;
  }
  tail->next = move(newNode);
  tail = tail->next;
  increaseSize();
}

void LinkedList::clear() {
  head = nullptr;
  tail = nullptr;
  clearSize();
}
long LinkedList::get(const int element) const {
  std::shared_ptr<Node> current = head;
  long index = 0;
  while (current != nullptr) {
    if (current->data == element) return index;
    current = current->next;
    index++;
  }
  return -1;
}
void LinkedList::print() const {
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
void LinkedList::remove(const long index) {
  if (index == 0) {
    head = std::move(head->next);
    if (getSize() == 1) {
      tail = nullptr;
    }
    decreaseSize();
    return;
  }
  auto current = head;
  for (long i = 0; i < index-1; i++) {
    current = current->next;
  }
  current->next = std::move(current->next->next);
  if (index == getSize() - 1) {
    tail = current;
  }
  decreaseSize();
}