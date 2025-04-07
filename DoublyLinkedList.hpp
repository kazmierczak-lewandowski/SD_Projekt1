//
// Created by piotr on 06.04.25.
//

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include <memory>
#include <iostream>

#include "Collection.hpp"
/**
 * \class DoublyLinkedList
 * \brief Implementation of a linked list class derived from Collection.
 */
class DoublyLinkedList final : public Collection{
private:
  struct Node {
    std::shared_ptr<Node> next = nullptr; ///< Pointer to the next node.
    std::shared_ptr<Node> previous = nullptr; ///< Pointer to the previous node.
    int data; ///< Data stored in the node.
    explicit Node(const int value) : data(value) {}
  };
  std::shared_ptr<Node> head = nullptr; ///< Pointer to the first node.
  std::shared_ptr<Node> tail = nullptr; ///< Pointer to the last node.

public:
  /**
   * \brief Default constructor for the LinkedList class.
   */
  explicit DoublyLinkedList() = default;

  /**
   * \copydoc Collection::print() const
   */
  void print() const override;

  /**
   * \copydoc Collection::add(int, long)
   */
  void add(int element, long index) override;
  /**
   * \copydoc Collection::add(int)
   */
  void add(int element) override;
  /**
   * \copydoc Collection::remove(long)
   */
  void remove(long index) override;

  /**
   * \copydoc Collection::clear()
   */
  void clear() override;

  /**
   * \copydoc Collection::getFirst() const
   */
  [[nodiscard]] int getFirst() const override { return head->data; }

  /**
   * \copydoc Collection::getLast() const
   */
  [[nodiscard]] int getLast() const override { return tail->data; }

  /**
   * \copydoc Collection::get(int) const
   */
  [[nodiscard]] long get(int element) const override;
};



#endif //DOUBLYLINKEDLIST_HPP
