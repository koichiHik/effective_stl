
//
#include <iostream>


//
#include <algorithm>

bool stl_accumulate_test() {

  std::cout << "Accumulate Test with Proper Init Value (double)" << std::endl;
  std::vector<double> vec1 = {1.0, 2.0, 3.0, 4.5, 3.5};
  double val1 = std::accumulate(vec1.begin(), vec1.end(), 0.0);
  std::cout << "Accumulated Sum : " << val1 << std::endl;

  std::cout << "Accumulate Test with NonProper Init Value (int)" << std::endl;
  std::vector<double> vec2 = {1.0, 2.0, 3.0, 4.5, 3.5};
  double val2 = std::accumulate(vec2.begin(), vec2.end(), 0);
  std::cout << "Accumulated Sum : " << val2 << std::endl;

  return true;
}

template<typename T>
struct PrintValFunctor :
  public std::unary_function<T, void> {
  void operator()(const T& v) {
    std::cout << v << std::endl;
  }
};

bool stl_for_each_test() {

  // Template Parameter の明示パターン．
  std::vector<std::string> vec{"Mark", "Sam", "Tom", "Math"};
  std::for_each(vec.begin(), vec.end(), PrintValFunctor<std::string>());

  return true;
}

int main(int, char**) {

  stl_accumulate_test();

  stl_for_each_test();

  return 0;
}