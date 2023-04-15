// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
   T* arr;
   int sizeMax, firstN, lastN, num;
 
 public:
   TPQuene():sizeMax(size), firstN(0), lastN(0), num(0) {
     arr = new T[sizeMax + 1];
   }

   ~TPQuene() {
     delete[] arr;
   }

  void push(const T& value) {
    assert(num < sizeMax);
    if (num == 0) {
      arr[lastN++] == value;
      num++;
    } else {
      int i = lastN - 1;
      bool fl = 0;
      while (i >= firstN && value.prior > arr[i].prior) {
        fl = 1;
        arr[i + 1] = arr[i];
        arr[i] = value;
        i--;
      }
      if (fl == 0) {
        arr[lastN] = value;
      }
      lastN++;
      num++;
    }
    if (lastN > sizeMax) {
      lastN -= sizeMax + 1;
    }
  }

  const T& pop() {
    assert(num > 0);
    num--;
    if (firstN > sizeMax) {
      firstN -= sizeMax + 1;
    }
    return arr[firstN++];
  }

  char get() {
    assert(num > 0);
    return arr[firstN].ch;
  }

  bool isFull() const {
    return num == sizeMax;
  }

  bool isEmpty() const {
    return num == 0;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
