#include <iostream>

template <typename T1, typename T2> void iter(T1 &array, size_t l, T2 func) {
  for (size_t i = 0; i < l; i++)
    func(array[i]);
}

class Awesome {
public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

private:
  int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

template <typename T> void print(T &x) {
  std::cout << x << std::endl;
  return;
}

int main() {
  int *tab = new int[]{0, 1, 2, 3, 4};
  Awesome tab2[5];

  iter(tab, 5, print<const int>);
  iter(tab2, 5, print<Awesome>);

  return 0;
}
