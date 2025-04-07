//
// Created by kazik on 4/6/25.
//
#include "Collection.hpp"

#include "Utils.hpp"

#include <fstream>
#include <random>

void Collection::fillWithRandom(Collection& collection) {
  for (int i = 0; i < collection.getSize(); i++) {
    collection.add(Utils::rng(0, 1000000));
  }
}

void Collection::fillFromFile(Collection& collection,
                              const std::string& filename) {
  std::ifstream file(filename);
  int element;
  while (file >> element) {
    collection.add(element);
  }
}