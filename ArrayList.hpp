//
// Created by kazik on 3/31/25.
//

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>
#include <memory>

#include "Collection.hpp"

/**
 * \class ArrayList
 * \brief A dynamic array implementation of the Collection class.
 */
class ArrayList final : private Collection {
 private:
  long capacity; ///< The current capacity of the array.
  long size = 0L; ///< The current number of elements in the array.
  std::unique_ptr<int[]> elements; ///< The array of elements.

  /**
   * \brief Ensures that the array has enough capacity to add new elements.
   */
  void ensureCapacity();

  /**
   * \brief Grows the array to accommodate more elements.
   */
  void grow();

 public:
  static constexpr long DEFAULT_CAPACITY = 10; ///< The default capacity of the array.

  /**
   * \brief Constructs an ArrayList with the specified capacity.
   * \param capacity The initial capacity of the array.
   * \throws std::invalid_argument if the capacity is less than or equal to 0.
   */
  explicit ArrayList(int capacity = DEFAULT_CAPACITY);

  /**
   * \brief Prints the elements of the array.
   */
  void print() const override;

  /**
   * \brief Adds an element to the array.
   * \param element The element to add.
   */
  void add(int element) override;

  /**
   * \brief Removes an element from the array at the specified index.
   * \param index The index of the element to remove.
   */
  void remove(long index) override;

  /**
   * \brief Clears all elements from the array.
   */
  void clear() override;

  /**
   * \brief Checks if the array is empty.
   * \return True if the array is empty, false otherwise.
   */
  [[nodiscard]] bool isEmpty() const override { return size == 0; }

  /**
   * \brief Gets the first element in the array.
   * \return The first element in the array.
   */
  [[nodiscard]] int getFirst() const override { return elements[0]; }

  /**
   * \brief Gets the last element in the array.
   * \return The last element in the array.
   */
  [[nodiscard]] int getLast() const override { return elements[size - 1]; }

  /**
   * \brief Gets the index of the specified element in the array.
   * \param element The element to find.
   * \return The index of the element, or -1 if not found.
   */
  [[nodiscard]] long get(int element) const override;

  /**
   * \brief Gets the size of the array.
   * \return The number of elements in the array.
   */
  [[nodiscard]] long getSize() const override { return size; }
};

#endif  // ARRAYLIST_HPP