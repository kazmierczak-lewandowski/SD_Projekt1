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
  constexpr static int ITERATIONS = 30;

  static long initCollectionsForTests(int size, ArrayList &arrayList,
                                      LinkedList &linkedList,
                                      DoublyLinkedList &doublyLinkedList);
  static std::vector<long> testAddTime(ArrayList &arrayList,
                                       LinkedList &linkedList,
                                       DoublyLinkedList &doublyLinkedList,
                                       long index);
  static std::vector<long> testAddTimeAverage(int size, long index);
  static std::vector<long> testRemoveTime(ArrayList &arrayList,
                                          LinkedList &linkedList,
                                          DoublyLinkedList &doublyLinkedList,
                                          long index);
  static std::vector<long> testRemoveTimeAverage(int size, long index);
  static std::vector<std::map<int, long>>
  analyzeAdding(int minSize, int maxSize, int index, const char *message);
  static std::vector<std::map<int, long>> analyzeAddFront(int minSize,
                                                          int maxSize);
  static std::vector<std::map<int, long>> analyzeAddBack(int minSize,
                                                         int maxSize);
  static std::vector<std::map<int, long>>
  analyzeRemove(int minSize, int maxSize, int index, const char *message);
  static std::vector<std::map<int, long>> analyzeRemoveFront(int minSize,
                                                             int maxSize);
  static std::vector<std::map<int, long>> analyzeRemoveBack(int minSize,
                                                            int maxSize);
  static std::vector<std::map<int, long>> analyzeRandomFind(int minSize,
                                                            int maxSize);

public:
  static void writeToFile(const std::string &filename,
                          const std::map<int, long> &data);
  static void analyze(int minSize, int maxSize);
};

#endif // ANALYSIS_HPP