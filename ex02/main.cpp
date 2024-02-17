#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

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

template <typename T> Array<T>::Array() : ArraySize(0), value(new T[0]()) {}

template <typename T>
Array<T>::Array(unsigned int n) : ArraySize(n), value(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array<T> &other)
    : ArraySize(other.ArraySize), value(new T[other.ArraySize]()) {
  for (size_t i = 0; i < this->ArraySize; i++)
    this->value[i] = other.value[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    if (this->value)
      delete[] this->value;
    this->value = new T[other.ArraySize]();
    this->ArraySize = other.ArraySize;
    for (size_t i = 0; i < this->ArraySize; i++)
      this->value[i] = other.value[i];
  }
  return *this;
}

template <typename T> Array<T>::~Array() {
  if (this->value)
    delete[] this->value;
};

template <typename T> T &Array<T>::operator[](size_t pos) {
  if (size() <= pos)
    throw std::out_of_range("Index is out of bounds");
  return this->value[pos];
}

template <typename T> const T &Array<T>::operator[](size_t pos) const {
  if (size() <= pos)
    throw std::out_of_range("Index is out of bounds");
  return this->value[pos];
}

template <typename T> size_t Array<T>::size() const { return this->ArraySize; }

int main() {
  try {
    Array<int> ar(5);
    Array<std::string> str(2);
    {
      Array<int> cp;
      cp = ar;
      std::cout << "Cp is " << cp[4] << std::endl;
    }
    ar[0] = 10;
    ar[1] = 20;
    str[0] = "Ayoub";
    str[1] = "Hamou";
    std::cout << ar[1] << std::endl;
    std::cout << "(" << str[0] << ")" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
