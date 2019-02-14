
// System Library
#include <iostream>

// STL Headers
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

bool stl_remove_not_change_size_test() {

  // 初期化  
  vector<int> v_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // vector の値を cout にコピー．
  std::cout << std::endl;
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  // Vector から奇数を remove するが，要素数に対する変化はなし．
  remove(v_int.begin(), v_int.end(), 3);
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  return true;
}

bool stl_erase_with_help_from_remove() {

  // 初期化  
  vector<int> v_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  // remove & erase のコンビネーションで初めて要素が削除される．
  v_int.erase(remove(v_int.begin(), v_int.end(), 3));
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  return true;
}

struct OddCheckFunctor : public unary_function<int, bool>{
  bool operator()(const int& a) const {
    return a % 2 == 1;
  }
};

bool stl_remove_if_with_functor() {

  // 初期化
  vector<int> v_int = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  std::cout << "Functor を使った奇数番号の削除...." << std::endl;
  v_int.erase(remove_if(v_int.begin(), v_int.end(), OddCheckFunctor()), v_int.end());
  copy(v_int.begin(), v_int.end(), ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  return true;
}


int main(int, char**) {


  std::cout << __FILE__ << " Started!" <<std::endl;
  std::cout << "stl_remove_not_change_size_test" << std::endl;
  stl_remove_not_change_size_test();

  std::cout << std::endl;
  std::cout << "stl_erase_with_help_from_remove" << std::endl;
  stl_erase_with_help_from_remove();

  std::cout << std::endl;
  std::cout << "stl_remove_if_with_functor" << std::endl;
  stl_remove_if_with_functor();

  return 0;
}