//
// Created by kazik on 4/7/25.
//

#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP
#include "ArrayList.hpp"
#include "LinkedList.hpp"

#include <map>
#include <vector>

class Analysis {
private:
  static std::vector<std::map<int, long>>
  analyzeAddingRandom(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeAddingFront(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeAddingBack(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeRemovingRandom(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeRemovingFront(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeRemovingBack(int minSize, int maxSize);
  static std::vector<std::map<int, long>>
  analyzeRandomFind(int minSize, int maxSize);
public:
  static void writeToFile(const std::string &filename,
                          const std::map<int, long> &data);

public:
  static void analyze(int minSize, int maxSize);
};

#endif // ANALYSIS_HPP