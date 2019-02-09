
// Starndard Library
#include <iostream>

// STL
#include <algorithm>
#include <functional>
#include <vector>

// Functor Class
struct PrintFunctor
{
  void operator()(int a) { std::cout << a << std::endl; }
};

struct IntCompare : public std::binary_function<int, int, bool>
{
  bool operator()(int lhs, int rhs) { return lhs < rhs; }
};

template <typename _Ty>
std::ostream &operator<<(std::ostream &ostr, const std::vector<_Ty> &v)
{
  if (v.empty())
  {
    ostr << "{ }";
    return ostr;
  }
  ostr << "{" << v.front();
  for (auto itr = ++v.begin(); itr != v.end(); itr++)
  {
    ostr << ", " << *itr;
  }
  ostr << "}";
  return ostr;
}

int main(int, char **)
{
  std::cout << __FILE__ << " Started!" << std::endl;
  // Functor クラスのテスト
  {
    PrintFunctor pfunc;
    pfunc(1);
  }

  // STL を使ったソート
  {
    std::vector<int> intVec = {10, 100, 45, 89};
    std::cout << intVec << std::endl;
    std::sort<std::vector<int>::iterator>(intVec.begin(), intVec.end(),
                                          IntCompare());
    std::cout << intVec << std::endl;
  }

  return 0;
}