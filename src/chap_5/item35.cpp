
// Sytem Library
#include <iostream>

// STL
#include <algorithm>
#include <string>

using namespace std;

void lexicographical_test();
void mismatch_test();

void lexicographical_test() {

  std::string s1("AAA");
  std::string s2("BBB");

  // lexicographical_compare のテスト．先のものが順序的に前に来なければ，０を返す．
  std::cout << std::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) << std::endl;

  // lexicographical_compare のテスト．先のものが順序的に前にくれば１を返す．
  std::cout << std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << std::endl;

  // lexicographical_compare のテスト．先のものが順序的に前に来なければ，０を返す．
  std::cout << std::lexicographical_compare(s2.begin(), s2.end(), s1.begin(), s1.end()) << std::endl;

}

void mismatch() {
  
}

void to_lower_test() {
  int c1 = std::tolower(static_cast<unsigned char>('A'));
  int c2 = std::tolower(static_cast<unsigned char>('B'));

  std::cout << static_cast<unsigned char>(c1) << std::endl;
  std::cout << static_cast<unsigned char>(c2) << std::endl;
}

int ciCharCompare(char c1, char c2) {
  int lc1 = std::tolower(static_cast<unsigned char>(c1));
  int lc2 = std::tolower(static_cast<unsigned char>(c2));

  // c1が先に来る場合，-1, c2が先に来る場合，1, 等しい場合は 0
  if (lc1 < lc2) { 
    return -1;
  } else if (lc2 < lc1) {
    return 1;
  }
  return 0;
}

int ciStringCompareImpl(const string& s1, const string& s2) {

  typedef pair<string::const_iterator, string::const_iterator> PSCI;

  // ciCharCompareがFalseを返したところで返ってくる．
  PSCI p = mismatch(s1.begin(), s1.end(), s2.begin(), s2.end(), ciCharCompare);

  return 0;
}

int main(int, char**) {

  std::cout << __FILE__ << " Started!" <<std::endl;

  // lexicographical_compare 
  std::cout << "std::lexicographical_compare() のテスト．" << std::endl;
  lexicographical_test();

  // tolower test
  std::cout << "std::tolower() のテスト．" << std::endl;
  to_lower_test();

  return 0;
}