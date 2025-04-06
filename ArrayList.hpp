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
  * \details If the array is full, it calls ArrayList::grow().
  */
 void ensureCapacity();

 /**
  * \brief Grows the array to accommodate more elements.
  * \details Grows the array to double its current size.
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
  * \copydoc Collection::isEmpty() const
  */
 [[nodiscard]] bool isEmpty() const override { return size == 0; }

 /**
  * \copydoc Collection::getFirst() const
  */
 [[nodiscard]] int getFirst() const override { return elements[0]; }

 /**
  * \copydoc Collection::getLast() const
  */
 [[nodiscard]] int getLast() const override { return elements[size - 1]; }

 /**
  * \copydoc Collection::get(int) const
  */
 [[nodiscard]] long get(int element) const override;

 /**
  * \copydoc Collection::getSize() const
  */
 [[nodiscard]] long getSize() const override { return size; }
};

#endif  // ARRAYLIST_HPP