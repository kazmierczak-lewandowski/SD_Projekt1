//
// Created by kazik on 4/3/25.
//

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <string>

/**
 * \class Collection
 * \brief Abstract base class for a collection of elements.
 */
class Collection {
 private:
  long size = 0L;  ///< The current number of elements in the array.

 protected:
  void increaseSize() { size++; }
  void decreaseSize() { size--; }
  void clearSize() { size = 0; }

 public:
  /**
   * \brief Virtual destructor for the Collection class.
   */
  virtual ~Collection() = default;
  /**
   * \brief Gets the size of the collection.
   * \return The number of elements in the collection.
   */
  [[nodiscard]] long getSize() const { return size; }
  /**
   * \brief Fills the collection with random elements.
   * \param collection The collection to fill.
   * \param size The number of random elements to add.
   */
  static void fillWithRandom(Collection& collection, long size);

  /**
   * \brief Fills the collection with elements from a file.
   * \param collection The collection to fill.
   * \param filename The name of the file to read elements from.
   */
  static void fillFromFile(Collection& collection, const std::string& filename);
  /**
   * \brief Prints the elements of the collection.
   */
  virtual void print() const = 0;
  /**
   * \brief Adds an element to the collection at the specified index.
   * \details Can be used to add at the end using index equal to size.
   * \param element The element to add.
   * \param index The index at which to add the element.
   */
  virtual void add(int element, long index) = 0;
  /**
   * \brief Adds an element to the collection at the end.
   * \param element The element to add.
   */
  virtual void add(int element) = 0;
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
  [[nodiscard]] bool isEmpty() const { return getSize() == 0; }
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
};

#endif  // COLLECTION_HPP