#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  size_t ArraySize;
  T *value;

public:
  Array<T>();
  Array<T>(unsigned int n);
  Array<T>(const Array<T> &other);
  Array<T> &operator=(const Array<T> &other);
  ~Array<T>();

  size_t size() const;
  T &operator[](size_t pos);
  const T &operator[](size_t pos) const;
};

template <typename T> Array<T>::Array() {
  this->ArraySize = 0;
  this->value = new T[0]();
}

template <typename T> Array<T>::Array(unsigned int n) {
  this->ArraySize = n;
  this->value = new T[n]();
}

template <typename T> Array<T>::Array(const Array<T> &other) {
  for (int i = 0; i < this->ArraySize; i++)
    this->value[i] = other.value[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    if (this->value)
      delete this->value;
    this->value = new T[other.ArraySize]();
    this->ArraySize = other.ArraySize;
    for (int i = 0; i < this->ArraySize; i++)
      this->value[i] = other.value[i];
  }
  return *this;
}

template <typename T> Array<T>::~Array() {
  if (this->value)
    delete[] this->value;
};

template <typename T> T &Array<T>::operator[](size_t pos) {
  if (size() < pos)
    throw std::out_of_range("Index is out of bounds");
  else
    return this->value[pos];
}

template <typename T> const T &Array<T>::operator[](size_t pos) const {
  if (size() < pos)
    throw std::out_of_range("Index is out of bounds");
  else
    return this->value[pos];
}

int main() {}
