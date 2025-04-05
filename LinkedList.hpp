//
// Created by piotr on 01.04.25.
//

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <memory>
#include <iostream>

#include "Collection.hpp"

/**
 * \class LinkedList
 * \brief Implementacja listy połączonej klasy Collection.
 */
class LinkedList final : private Collection {
private:
  struct Node {
    std::unique_ptr<Node> next = nullptr; ///< Wskaźnik na następny węzeł.
    int data; ///< Dane przechowywane w węźle.
    explicit Node(int value) : data(value) {}
  };
  std::unique_ptr<Node> head = nullptr; ///< Wskaźnik na pierwszy węzeł.
  Node* tail = nullptr; ///< Wskaźnik na ostatni węzeł.

public:
  /**
   * \brief Konstruktor domyślny klasy LinkedList.
   */
  explicit LinkedList();

  /**
   * \copydoc Collection::print() const
   */
  void print() const override;

  /**
   * \copydoc Collection::add(int, long)
   */
  void add(int element, long index) override;

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

#endif //LINKEDLIST_HPP