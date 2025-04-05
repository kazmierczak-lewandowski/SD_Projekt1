//
// Created by kazik on 4/3/25.
//

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

/**
 * \class Collection
 * \brief Abstract base class for a collection of elements.
 */
class Collection {
public:
  /**
   * \brief Virtual destructor for the Collection class.
   */
  virtual ~Collection() = default;

private:
  /**
   * \brief Prints the elements of the collection.
   */
  virtual void print() const = 0;

  /**
  * \brief Adds an element to the collection at the specified index.
  * \param element The element to add.
  * \param index The index at which to add the element.
  * \throws std::out_of_range if the index is out of range.
  */
  virtual void add(int element, long index) = 0;

  /**
   * \brief Removes an element from the collection at the specified index.
   * \param index The index of the element to remove.
   */
  virtual void remove(long index) = 0;

  /**
   * \brief Clears all elements from the collection.
   */
  virtual void clear() = 0;

  /**
   * \brief Checks if the collection is empty.
   * \return True if the collection is empty, false otherwise.
   */
  [[nodiscard]] virtual bool isEmpty() const = 0;

  /**
   * \brief Gets the first element in the collection.
   * \return The first element in the collection.
   */
  [[nodiscard]] virtual int getFirst() const = 0;

  /**
   * \brief Gets the last element in the collection.
   * \return The last element in the collection.
   */
  [[nodiscard]] virtual int getLast() const = 0;

  /**
   * \brief Gets the index of the specified element in the collection.
   * \param element The element to find.
   * \return The index of the element, or -1 if not found.
   */
  [[nodiscard]] virtual long get(int element) const = 0;

  /**
   * \brief Gets the size of the collection.
   * \return The number of elements in the collection.
   */
  [[nodiscard]] virtual long getSize() const = 0;
};

#endif // COLLECTION_HPP