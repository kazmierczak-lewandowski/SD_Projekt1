//
// Created by kazik on 4/6/25.
//
#include "Collection.hpp"

#include <fstream>
#include <random>

void Collection::fillWithRandom(Collection& collection, const long size) {
  collection.clear();
  std::random_device rd;
  std::mt19937 rand(rd());
  std::uniform_int_distribution dist(0, 1000000);
  for (int i = 0; i < size; i++) {
    collection.add(dist(rand));
  }
}
void Collection::fillFromFile(Collection& collection,
                              const std::string& filename) {
  collection.clear();
  std::ifstream file(filename);
  int element;
  while (file >> element) {
    collection.add(element);
  }
}