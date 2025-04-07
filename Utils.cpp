//
// Created by kazik on 4/7/25.
//

#include "Utils.hpp"

#include <random>
int Utils::rng(const int min, const int max) {
  std::random_device rd;
  std::mt19937 rand(rd());
  std::uniform_int_distribution dist(min, max);
  return dist(rand);
}