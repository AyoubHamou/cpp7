#pragma once
#include <iostream>

template <typename T1, typename T2> void iter(T1 &array, size_t l, T2 func) {
  for (size_t i = 0; i < l; i++)
    func(array[i]);
}
