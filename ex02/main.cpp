#include "Array.hpp"

int main() {
  try {
    Array<int> ar(5);
    Array<std::string> str(2);

    ar[0] = 10;
    ar[1] = 20;
    str[0] = "Ayoub";
    str[1] = "Hamou";

    {
      Array<int> cp; // test = operator
      cp = ar;
      cp[0] = 1;
      std::cout << "Cp[0] is " << cp[0] << std::endl;
      std::cout << "Cp[1] is " << cp[1] << std::endl;
    }
    {
      Array<std::string> str2(str); // test copy construtor
      std::cout << str2[0] << std::endl;
    }
    std::cout << ar[1] << std::endl;
    std::cout << "(" << str[0] << ")" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
