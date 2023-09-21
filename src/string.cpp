#include "technikumSTL/string.h"

#include <cstring>

namespace technikum
{
  string::string(const char* str)
  {
    len = strlen(str);
    data = new char[len + 1];
    strcpy_s(data, len + 1, str);
  }

  string::string() : data(nullptr), len(0)
  {
  }

  string::~string()
  {
    delete[] data;
  }

  void string::append(const string& other)
  {
    int newLen = len + other.len;
    char* newData = new char[newLen + 1];
    strcpy_s(newData, newLen + 1, data);
    strcat_s(newData, newLen + 1, other.data);

    delete[] data;
    data = newData;
    len = newLen;
  }

  const char* string::c_str() const
  {
    return data;
  }

  int string::length() const
  {
    return len;
  }

  int string::size() const
  {
    return len;
  }
}  // namespace technikum
