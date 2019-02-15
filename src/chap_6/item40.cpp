
// Starndard Library
#include <iostream>

// STL
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

struct Print2StringFunctor : public binary_function<string, string, void>
{
  void operator()(const string &s1, const string &s2) const
  {
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
  }
};

bool test_binder()
{
  cout << "Bind による 1番目引数の固定" << endl;
  bind1st(Print2StringFunctor(), "1st")("2nd");
  std::cout << std::endl;

  cout << "Bind による 2番目引数の固定" << endl;
  bind2nd(Print2StringFunctor(), "2nd")("1st");
  std::cout << std::endl;
  return true;
}

class Object
{
public:
  Object(int id) : m_id(id) {}
  int m_id;
  friend ostream &operator<<(ostream &os, const Object &obj)
  {
    os << obj.m_id;
    return os;
  }
};

template <typename T>
bool isInteresting(const T &obj)
{
  return obj.m_id % 3 == 0;
}

bool test_find_if_with_raw_funcptr()
{
  vector<Object> vec{Object(1), Object(2), Object(3), Object(4),
                     Object(5), Object(6), Object(7)};

  std::cout << "Vector の m_id を出力" << std::endl;
  copy(vec.begin(), vec.end(), ostream_iterator<Object>(std::cout, ", "));
  std::cout << std::endl;

  {
    std::cout << "find_if による id が 3 の倍数の最初のオブジェクトの検索"
              << std::endl;
    vector<Object>::iterator itr =
        find_if(vec.begin(), vec.end(), isInteresting<Object>);
    std::cout << itr->m_id << std::endl;
    std::cout << std::endl;
  }

  {
    std::cout << "ptr_fun による関数ポインタの関数オブジェクトへの変換"
              << std::endl;
    vector<Object>::iterator itr =
        find_if(vec.begin(), vec.end(), ptr_fun(isInteresting<Object>));
    std::cout << itr->m_id << std::endl;
    std::cout << std::endl;
  }

  {
    std::cout << "not1 & ptr_fun による関数ポインタの反転" << std::endl;
    vector<Object>::iterator itr =
        find_if(vec.begin(), vec.end(), not1(ptr_fun(isInteresting<Object>)));
    std::cout << itr->m_id << std::endl;
    std::cout << std::endl;
  }

  return true;
}

int main(int, char **)
{
  std::cout << __FILE__ << std::endl;

  // Test Binder
  test_binder();

  // Test Findif with raw Pointers.
  test_find_if_with_raw_funcptr();

  return 0;
}