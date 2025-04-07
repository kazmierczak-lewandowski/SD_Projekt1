//
// Created by kazik on 4/7/25.
//

#include "Analysis.hpp"

#include "Utils.hpp"

#include <chrono>
#include <fstream>
#include <print>
long Analysis::initCollectionsForTests(const int size, ArrayList &arrayList,
                                          LinkedList &linkedList,
                                          DoublyLinkedList &doublyLinkedList) {
  std::ifstream ifs("../random_integers.txt");
  if (!ifs.is_open()) {
    std::cerr << "Failed to open file random_integers.txt" << std::endl;
  }
  const int randIndex = Utils::rng(0, size - 1);
  long ret = 0;
  for (int k = 0; k < size; k++) {
    int number;
    ifs >> number;
    if (k == randIndex) {
      ret = number;
    }
    arrayList.add(number);
    linkedList.add(number);
    doublyLinkedList.add(number);
  }
  ifs.close();
  return ret;
}

std::vector<long> Analysis::testAddTime(ArrayList &arrayList,
                                           LinkedList &linkedList,
                                           DoublyLinkedList &doublyLinkedList,
                                           const long index) {
  const int value = Utils::rng(0, 10000000);
  // Testing ArrayList
  auto start = std::chrono::high_resolution_clock::now();
  arrayList.add(value, index);
  auto finish = std::chrono::high_resolution_clock::now();
  long res1 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();

  // Testing LinkedList
  start = std::chrono::high_resolution_clock::now();
  linkedList.add(value, index);
  finish = std::chrono::high_resolution_clock::now();
  long res2 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();

  // Testing DoublyLinkedList
  start = std::chrono::high_resolution_clock::now();
  doublyLinkedList.add(value, index);
  finish = std::chrono::high_resolution_clock::now();
  long res3 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();
  return {res1, res2, res3};
}

std::vector<long> Analysis::testAddTimeAverage(const int size,
                                               const long index) {
  long res1 = 0;
  long res2 = 0;
  long res3 = 0;
  for (int i = 0; i < ITERATIONS; i++) {
    ArrayList arrayList(size + 1);
    LinkedList linkedList;
    DoublyLinkedList doublyLinkedList;

    initCollectionsForTests(size, arrayList, linkedList, doublyLinkedList);
    std::print("{} test for {}\n", i, size);
    std::vector<long> results;
    if (index == -1)
      results = testAddTime(arrayList, linkedList, doublyLinkedList,
                            Utils::rng(size / 4, size - size / 4));
    else if (index == -2)
      results = testAddTime(arrayList, linkedList, doublyLinkedList, size);
    else
      results = testAddTime(arrayList, linkedList, doublyLinkedList, index);
    res1 += results[0];
    res2 += results[1];
    res3 += results[2];
  }
  return {res1 / ITERATIONS, res2 / ITERATIONS, res3 / ITERATIONS};
}
std::vector<long> Analysis::testRemoveTime(ArrayList &arrayList,
                                           LinkedList &linkedList,
                                           DoublyLinkedList &doublyLinkedList,
                                           const long index) {
  // Testing ArrayList
  auto start = std::chrono::high_resolution_clock::now();
  arrayList.remove(index);
  auto finish = std::chrono::high_resolution_clock::now();
  long res1 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();

  // Testing LinkedList
  start = std::chrono::high_resolution_clock::now();
  linkedList.remove(index);
  finish = std::chrono::high_resolution_clock::now();
  long res2 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();

  // Testing DoublyLinkedList
  start = std::chrono::high_resolution_clock::now();
  doublyLinkedList.remove(index);
  finish = std::chrono::high_resolution_clock::now();
  long res3 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count();
  return {res1, res2, res3};
}

std::vector<long> Analysis::testRemoveTimeAverage(int size, long index) {
  long res1 = 0;
  long res2 = 0;
  long res3 = 0;
  for (int i = 0; i < ITERATIONS; i++) {
    ArrayList arrayList(size + 1);
    LinkedList linkedList;
    DoublyLinkedList doublyLinkedList;

    initCollectionsForTests(size, arrayList, linkedList, doublyLinkedList);
    std::print("{} test for {}\n", i, size);
    std::vector<long> results;
    if (index == -1)
      results = testRemoveTime(arrayList, linkedList, doublyLinkedList,
                            Utils::rng(size / 4, size - size / 4));
    else if (index == -2)
      results = testRemoveTime(arrayList, linkedList, doublyLinkedList, size-1);
    else
      results = testRemoveTime(arrayList, linkedList, doublyLinkedList, index);
    res1 += results[0];
    res2 += results[1];
    res3 += results[2];
  }
  return {res1 / ITERATIONS, res2 / ITERATIONS, res3 / ITERATIONS};
}
std::vector<std::map<int, long>> Analysis::analyzeAdding(const int minSize,
                                                         const int maxSize,
                                                         const int index,
                                                         const char *message) {
  std::cout << message << std::endl;
  std::map<int, long> data1;
  std::map<int, long> data2;
  std::map<int, long> data3;
  for (int i = minSize; i <= maxSize; i += 100000) {
    std::vector<long> results;
    results = testAddTimeAverage(i, index);
    data1.insert(std::pair(i, results[0]));
    data2.insert(std::pair(i, results[1]));
    data3.insert(std::pair(i, results[2]));
    std::print("Test for {} ended\n", i);
  }
  return {data1, data2, data3};
}

std::vector<std::map<int, long>> Analysis::analyzeAddFront(const int minSize,
                                                           const int maxSize) {
  return analyzeAdding(minSize, maxSize, 0, "Analyzing Adding at the Front");
}
std::vector<std::map<int, long>> Analysis::analyzeAddBack(const int minSize,
                                                          const int maxSize) {
  return analyzeAdding(minSize, maxSize, -2, "Analyzing Adding at the Front");
}

std::vector<std::map<int, long>>
Analysis::analyzeRemove(const int minSize, const int maxSize, const int index,
                          const char *message) {
  std::cout << message << std::endl;
  std::map<int, long> data1;
  std::map<int, long> data2;
  std::map<int, long> data3;
  for (int i = minSize; i <= maxSize; i += 100000) {
    std::vector<long> results;
    results = testRemoveTimeAverage(i, index);
    data1.insert(std::pair(i, results[0]));
    data2.insert(std::pair(i, results[1]));
    data3.insert(std::pair(i, results[2]));
    std::print("Test for {} ended\n", i);
  }
  return {data1, data2, data3};
}
std::vector<std::map<int, long>> Analysis::analyzeRemoveFront(const int minSize, const int maxSize) {
  return analyzeRemove(minSize, maxSize, 0, "Analyzing Removing at the Front");
}
std::vector<std::map<int, long>>
Analysis::analyzeRemoveBack(const int minSize, const int maxSize) {
  return analyzeRemove(minSize, maxSize, -2, "Analyzing Removing at the Back");
}
std::vector<std::map<int, long>> Analysis::analyzeRandomFind(const int minSize, const int maxSize) {
  std::cout << "Analyzing finding random element" << std::endl;
  std::map<int, long> data1;
  std::map<int, long> data2;
  std::map<int, long> data3;
  for (int i = minSize; i <= maxSize; i += 100000) {
    long res1 = 0;
    long res2 = 0;
    long res3 = 0;
    for (int j = 0; j < ITERATIONS; j++) {

      ArrayList arrayList(j + 1);
      LinkedList linkedList;
      DoublyLinkedList doublyLinkedList;

      initCollectionsForTests(i, arrayList, linkedList, doublyLinkedList);
      const int elementToFind = (Utils::rng(0, i));
      std::print("{} test for {}\n", j, i);

      // Testing ArrayList
      auto start = std::chrono::high_resolution_clock::now();
      arrayList.get(elementToFind);
      auto finish = std::chrono::high_resolution_clock::now();
      res1 +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
              .count();

      // Testing LinkedList
      start = std::chrono::high_resolution_clock::now();
      linkedList.get(elementToFind);
      finish = std::chrono::high_resolution_clock::now();
      res2 +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
              .count();

      // Testing DoublyLinkedList
      start = std::chrono::high_resolution_clock::now();
      doublyLinkedList.get(elementToFind);
      finish = std::chrono::high_resolution_clock::now();
      res3 +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
              .count();

    }
    data1.insert(std::pair(i, res1 / ITERATIONS));
    data2.insert(std::pair(i, res2 / ITERATIONS));
    data3.insert(std::pair(i, res3 / ITERATIONS));
    std::print("Test for {} ended\n", i);
  }
  return {data1, data2, data3};
}
void Analysis::writeToFile(const std::string &filename,
                           const std::map<int, long> &data) {
  std::ofstream ofs("../results/" + filename);
  if (!ofs.is_open()) {
    std::cerr << "Failed to open file " << filename << std::endl;
  }
  ofs << "size;time" << std::endl;
  for (const auto &[key, value] : data) {
    ofs << key << ";" << value << std::endl;
  }
  ofs.close();
}
void Analysis::analyze(const int minSize, const int maxSize) {
  std::vector<std::map<int, long>> data;
  //     analyzeAdding(minSize, maxSize, -1, "Analyzing Adding at Random");
  // writeToFile("ArrayListRandomAdd.csv", data[0]);
  // writeToFile("LinkedListRandomAdd.csv", data[1]);
  // writeToFile("DoublyLinkedListRandomAdd.csv", data[2]);
  // data = analyzeAdding(minSize, maxSize, 0, "Analyzing Adding at the Front");
  // writeToFile("ArrayListFrontAdd.csv", data[0]);
  // writeToFile("LinkedListFrontAdd.csv", data[1]);
  // writeToFile("DoublyLinkedListFrontAdd.csv", data[2]);
  // data = analyzeAdding(minSize, maxSize, -2, "Analyzing Adding at the Back");
  // writeToFile("ArrayListBackAdd.csv", data[0]);
  // writeToFile("LinkedListBackAdd.csv", data[1]);
  // writeToFile("DoublyLinkedListBackAdd.csv", data[2]);
  // data = analyzeRemove(minSize, maxSize, -1, "Analyzing Removing at the Back");
  // writeToFile("ArrayListRandomRemove.csv", data[0]);
  // writeToFile("LinkedListRandomRemove.csv", data[1]);
  // writeToFile("DoublyLinkedListRandomRemove.csv", data[2]);
  // data = analyzeRemove(minSize, maxSize, 0, "Analyzing Removing at the Front");
  // writeToFile("ArrayListFrontRemove.csv", data[0]);
  // writeToFile("LinkedListFrontRemove.csv", data[1]);
  // writeToFile("DoublyLinkedListFrontRemove.csv", data[2]);
  // data = analyzeRemove(minSize, maxSize, -2, "Analyzing Removing at the Back");
  // writeToFile("ArrayListBackRemove.csv", data[0]);
  // writeToFile("LinkedListBackRemove.csv", data[1]);
  // writeToFile("DoublyLinkedListBackRemove.csv", data[2]);
  data = analyzeRandomFind(minSize, maxSize);
  writeToFile("ArrayListRandomFind.csv", data[0]);
  writeToFile("LinkedListRandomFind.csv", data[1]);
  writeToFile("DoublyLinkedListRandomFind.csv", data[2]);
}