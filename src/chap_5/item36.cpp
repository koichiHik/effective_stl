
// Sytem Library
#include <iostream>

// STL
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

bool validValue(int a) { return a % 3 == 0; }

void remove_copy_if_test() {
  vector<int> vec_src = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> vec_dst(vec_src.size());
  vector<int>::iterator end = remove_copy_if(vec_src.begin(), vec_src.end(),
                                             vec_dst.begin(), validValue);
  std::cout << vec_dst.size() << std::endl;
  std::ostream_iterator<int> cout_it(cout, ", ");
  copy(vec_dst.begin(), end, cout_it);
}

int main(int, char **) {

  std::cout << __FILE__ << " Started!" << std::endl;

  std::cout << "remove_copy_if のテスト" << std::endl;
  remove_copy_if_test();
  std::cout << std::endl;

  return 0;
}