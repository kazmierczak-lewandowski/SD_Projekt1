Here is the `Analysis.hpp` file documented using Doxygen comments:

```cpp
//
// Created by kazik on 4/7/25.
//

#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"
#include "LinkedList.hpp"

#include <map>
#include <vector>

/**
 * @class Analysis
 * @brief A class for analyzing the performance of various collection operations.
 */
class Analysis {
private:
  /**
   * @brief Number of iterations for performance tests.
   */
  constexpr static int ITERATIONS = 30;

  /**
   * @brief Initializes collections with test data.
   * @param size The size of the collections to initialize.
   * @param arrayList Reference to an ArrayList instance.
   * @param linkedList Reference to a LinkedList instance.
   * @param doublyLinkedList Reference to a DoublyLinkedList instance.
   * @return Random element of Collections.
   */
  static int initCollectionsForTests(int size, ArrayList &arrayList,
                                      LinkedList &linkedList,
                                      DoublyLinkedList &doublyLinkedList);
  /**
   * @brief Tests the time taken to add elements to collections.
   * @param arrayList Reference to an ArrayList instance.
   * @param linkedList Reference to a LinkedList instance.
   * @param doublyLinkedList Reference to a DoublyLinkedList instance.
   * @param index The index at which to add elements.
   * @return A vector of times taken for each collection.
   */
  static std::vector<long> testAddTime(ArrayList &arrayList,
                                       LinkedList &linkedList,
                                       DoublyLinkedList &doublyLinkedList,
                                       long index);
  /**
   * @brief Computes the average time taken to add elements to collections.
   * @param size The size of the collections.
   * @param index The index at which to add elements.
   * @return A vector of average times for each collection.
   */
  static std::vector<long> testAddTimeAverage(int size, long index);
  /**
   * @brief Tests the time taken to remove elements from collections.
   * @param arrayList Reference to an ArrayList instance.
   * @param linkedList Reference to a LinkedList instance.
   * @param doublyLinkedList Reference to a DoublyLinkedList instance.
   * @param index The index of the element to remove.
   * @return A vector of times taken for each collection.
   */
  static std::vector<long> testRemoveTime(ArrayList &arrayList,
                                          LinkedList &linkedList,
                                          DoublyLinkedList &doublyLinkedList,
                                          long index);
  /**
   * @brief Computes the average time taken to remove elements from collections.
   * @param size The size of the collections.
   * @param index The index of the element to remove.
   * @return A vector of average times for each collection.
   */
  static std::vector<long> testRemoveTimeAverage(int size, long index);
  /**
   * @brief Analyzes the time taken to add elements to collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @param index The index at which to add elements. -1 for random, -2 for back.
   * @param message A message describing the operation.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>>
  analyzeAdding(int minSize, int maxSize, int index, const char *message);
  /**
   * @brief Analyzes the time taken to add elements to the front of collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>> analyzeAddFront(int minSize,
                                                          int maxSize);
  /**
   * @brief Analyzes the time taken to add elements to the back of collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>> analyzeAddBack(int minSize,
                                                         int maxSize);
  /**
   * @brief Analyzes the time taken to remove elements from collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @param index The index at which to add elements. -1 for random, -2 for back.
   * @param message A message describing the operation.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>>
  analyzeRemove(int minSize, int maxSize, int index, const char *message);
  /**
   * @brief Analyzes the time taken to remove elements from the front of collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>> analyzeRemoveFront(int minSize,
                                                             int maxSize);
  /**
   * @brief Analyzes the time taken to remove elements from the back of collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>> analyzeRemoveBack(int minSize,
                                                            int maxSize);
  /**
   * @brief Analyzes the time taken to find random elements in collections.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   * @return A vector of maps containing the analysis results.
   */
  static std::vector<std::map<int, long>> analyzeRandomFind(int minSize,
                                                            int maxSize);
  /**
   * @brief Writes analysis results to a file.
   * @param filename The name of the file to write to.
   * @param data The analysis data to write.
   */
  static void writeToFile(const std::string &filename,
                          const std::map<int, long> &data);
public:
  /**
   * @brief Performs analysis on collections within a size range.
   * @param minSize The minimum size of the collections.
   * @param maxSize The maximum size of the collections.
   */
  static void analyze(int minSize, int maxSize);
};

#endif // ANALYSIS_HPP