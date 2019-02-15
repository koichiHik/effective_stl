
// System Library
#include <iostream>

//
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

class Object
{
public:
  Object(bool delete_flag) : m_delete(delete_flag){};
  bool toBeDeleted() const { return m_delete; }
  bool m_delete;
};

bool isSubjectToBeDeleted(const Object &obj) { return obj.toBeDeleted(); }

bool isSubjectToBeDeletedPtr(const Object *obj) { return obj->toBeDeleted(); }

bool test_remove_erase_with_shared_ptr()
{

  std::cout << "Object を格納する Vector に対する remove_if & erase"
            << std::endl;
  {
    vector<Object> objs{Object(true), Object(false), Object(true),
                        Object(false), Object(false)};
    objs.erase(remove_if(objs.begin(), objs.end(), isSubjectToBeDeleted),
               objs.end());
  }

  std::cout << "Pointer を格納する Vector に対する remove_if & erase　その１"
            << std::endl;
  std::cout << "このケースはリークする．" << std::endl;
  {
    vector<Object *> objs{new Object(true), new Object(false), new Object(true),
                          new Object(false), new Object(false)};
    objs.erase(remove_if(objs.begin(), objs.end(), isSubjectToBeDeletedPtr),
               objs.end());
  }

  std::cout << "Pointer を格納する Vector に対する remove_if & erase　その２"
            << std::endl;
  std::cout << "このケースはリークする．" << std::endl;
  {
    vector<Object *> objs{new Object(true), new Object(false), new Object(true),
                          new Object(false), new Object(false)};
    objs.erase(
        remove_if(objs.begin(), objs.end(), mem_fun(&Object::toBeDeleted)),
        objs.end());
  }

  std::cout << "Smart Pointer を格納する Vector に対する remove_if & erase"
            << std::endl;
  std::cout << "このケースはリークする．" << std::endl;
  {
    vector<shared_ptr<Object>> objs{shared_ptr<Object>(new Object(true)),
                                    shared_ptr<Object>(new Object(false)),
                                    shared_ptr<Object>(new Object(true)),
                                    shared_ptr<Object>(new Object(false)),
                                    shared_ptr<Object>(new Object(false))};

    objs.erase(
        remove_if(objs.begin(), objs.end(), [](shared_ptr<Object> const &ptr) {
          return ptr->toBeDeleted();
        }),
        objs.end());
  }

  return true;
}

int main(int, char **)
{
  test_remove_erase_with_shared_ptr();
  return 0;
}