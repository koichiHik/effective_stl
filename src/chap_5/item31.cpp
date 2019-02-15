
// Standard Library
#include <iostream>

// STL
#include <iterator>
#include <algorithm>

bool test_sort() {

  {
    // Sort 関数を使った Sort
    std::vector<int> vec_int{0, 3, 2, 2, 1, 10, 8};
    std::sort(vec_int.begin(), vec_int.end());
    std::copy(vec_int.begin(), vec_int.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }

  {
    // Stable Sort 関数を使った Sort
    std::vector<int> vec_int{0, 3, 2, 2, 1, 10, 8};
    std::stable_sort(vec_int.begin(), vec_int.end());
    std::copy(vec_int.begin(), vec_int.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }


  return true;
}

int main(int, char**) {

  std::cout << __FILE__ << std::endl;
  test_sort();






  return 0;
}