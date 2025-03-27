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
        std::cout << '[';
        for (long i = 0; i < size; i++) {
            std::cout << elements[i];
            if (i != size-1) {
                std::cout << ", ";
            }
            else
                std::cout << ']';

        }
        std::cout << std::endl;
    }
    void add(T element) {
        ensureCapacity();
        elements[size++] = element;
    }
    void removeIndex(const int index) {
        for (long i = index; i < size-1; i++) {
            elements[i] = elements[i+1];
        }
        elements[size];
        size--;

    }
    void removeElement(T element) {
        for (long i = 0; i < size; i++) {
            if (elements[i] == element) {
                removeIndex(i);
                return;
            }
        }
    }
};



#endif //ARRAYLIST_H
