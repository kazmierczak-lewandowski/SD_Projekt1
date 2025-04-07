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

class Analysis {
private:
  constexpr static int ITERATIONS = 25;

  static void initCollectionsForAddTests(int size, ArrayList &arrayList,
                                         LinkedList &linkedList,
                                         DoublyLinkedList &doublyLinkedList);
  static std::vector<long> testAddingTime(ArrayList &arrayList,
                                          LinkedList &linkedList,
                                          DoublyLinkedList &doublyLinkedList,
                                          long index);
  static std::vector<long> testAddingTimeAverage(int size, long index);
  static std::vector<std::map<int, long>>
  analyzeAdding(int minSize, int maxSize, int index,
                      const char *message);
  static std::vector<std::map<int, long>> analyzeAddingFront(int minSize,
                                                             int maxSize);
  static std::vector<std::map<int, long>> analyzeAddingBack(int minSize,
                                                            int maxSize);
  static std::vector<std::map<int, long>> analyzeRemovingRandom(int minSize,
                                                                int maxSize);
  static std::vector<std::map<int, long>> analyzeRemovingFront(int minSize,
                                                               int maxSize);
  static std::vector<std::map<int, long>> analyzeRemovingBack(int minSize,
                                                              int maxSize);
  static std::vector<std::map<int, long>> analyzeRandomFind(int minSize,
                                                            int maxSize);

public:
  static void writeToFile(const std::string &filename,
                          const std::map<int, long> &data);

public:
  static void analyze(int minSize, int maxSize);
};

#endif // ANALYSIS_HPP