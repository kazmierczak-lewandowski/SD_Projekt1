//
// Created by kazik on 4/7/25.
//

#include "Analysis.hpp"

#include "Utils.hpp"

#include <chrono>
#include <fstream>
#include <print>
std::vector<std::map<int, long>>
Analysis::analyzeAddingRandom(const int minSize, const int maxSize) {
  std::map<int, long> data1;
  std::map<int, long> data2;
  std::map<int, long> data3;
  for (int i = minSize; i <= maxSize; i += 100000) {
    ArrayList arrayList(i+1);
    LinkedList linkedList;
    // DoublyLinkedList doublyLinkedList;
    for (int j = 0; j < i; j++) {
      std::ifstream ifs("../random_integers.txt");
      if (!ifs.is_open()) {
        std::cerr << "Failed to open file random_integers.txt" << std::endl;
        return {};
      }
      int number;
      ifs >> number;
      arrayList.add(number);
      linkedList.add(number);
      // doublyLinkedList->add(number);
      ifs.close();
    }
    std::print("Testing for: {}", i);
    const long index = Utils::rng(0, i);
    const int value = Utils::rng(0, 10000000);
    //Testing ArrayList
    auto start = std::chrono::high_resolution_clock::now();
    arrayList.add(value, index);
    auto finish = std::chrono::high_resolution_clock::now();
    data1.insert(std::pair(
        i,
        std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
            .count()));
    //Testing LinkedList
    start = std::chrono::high_resolution_clock::now();
    linkedList.add(value, index);
    finish = std::chrono::high_resolution_clock::now();
    data2.insert(std::pair(
        i,
        std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
            .count()));
    //Testing DoublyLinkedList
    // start = std::chrono::high_resolution_clock::now();
    // doublyLinkedList.add(value, index);
    // finish = std::chrono::high_resolution_clock::now();
    // data3.insert(std::pair(
    //     i,
    //     std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
    //         .count()));

    std::print("Test for {} ended", i);
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
  const std::vector<std::map<int, long>> data =
      analyzeAddingRandom(minSize, maxSize);
  writeToFile("ArrayListRandomAdd.csv", data[0]);
  writeToFile("LinkedListRandomAdd.csv", data[1]);
  // writeToFile("DoublyLinkedListRandomAdd.csv", data[2]);
}