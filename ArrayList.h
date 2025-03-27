//
// Created by kazik on 3/27/25.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

template <typename T>
class ArrayList {
    private:
      long capacity;
      long size;
      T* elements;
      void ensureCapacity() {
          if (capacity == size+1) {
              grow();
          }
      };
    void grow() {
        auto temp = new T[size*2];
        for (long i = 0; i < size; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    };
  public:
    static constexpr long DEFAULT_CAPACITY = 10;

    explicit ArrayList(const int capacity = DEFAULT_CAPACITY) : capacity(capacity), size(0L) {
      if (capacity <= 0) throw std::invalid_argument("capacity must be greater than 0");
      elements = new T[capacity];
      }
    void print() const {
        for (long i = 0; i < size; i++) {
            std::cout << elements[i] << ", ";
        }
    }
    void add(T element) {
        ensureCapacity();
        elements[size++] = element;
    }
};



#endif //ARRAYLIST_H
