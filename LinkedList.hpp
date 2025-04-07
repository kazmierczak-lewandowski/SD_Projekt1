//
// Created by piotr on 01.04.25.
//

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <memory>

#include "Collection.hpp"

/**
 * \class LinkedList
 * \brief Implementation of a linked list class derived from Collection.
 */
class LinkedList final : public Collection {
private:
  struct Node {
    std::unique_ptr<Node> next = nullptr; ///< Pointer to the next node.
    int data;                             ///< Data stored in the node.
    explicit Node(const int value) : data(value) {}
  };
  std::unique_ptr<Node> head = nullptr; ///< Pointer to the first node.
  Node *tail = nullptr;                 ///< Pointer to the last node.

public:
  /**
   * \brief Default constructor for the LinkedList class.
   */
  explicit LinkedList() = default;
  /**
   * \brief Destructor for the LinkedList class.
   */
  ~LinkedList() override;
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

#endif // LINKEDLIST_HPP