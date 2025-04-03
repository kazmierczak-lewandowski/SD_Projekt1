//
// Created by kazik on 4/3/25.
//

#ifndef COLLECTION_HPP
#define COLLECTION_HPP



class Collection {
 public:
  virtual ~Collection() = default;

 private:
  virtual void print() const = 0;
  virtual void add(int element) = 0;
  virtual void remove(long index) = 0;
  virtual void clear() = 0;
  [[nodiscard]] virtual bool isEmpty() const;
  [[nodiscard]] virtual int getFirst() const = 0;
  [[nodiscard]] virtual int getLast() const = 0;
  [[nodiscard]] virtual long get(int element) const = 0;
  [[nodiscard]] virtual long getSize() const = 0;
};



#endif //COLLECTION_HPP
