#include "technikumSTL/string.h"

#include <cstring>

namespace technikum
{
  string::string() 
  {
    len = 0;
    data = nullptr;
  }

  string::string(const char* str)
  {
    len = strlen(str);
    data = new char[len + 1];
    strcpy_s(data, len + 1, str);
  }

  string::string(const string& other)
  {
    len = other.len;
    data = new char[len + 1];
    strcpy_s(data, len + 1, other.data);
  }

  string string::operator=(const string& other)
  {
    if (data)
    {
      delete[] data;
    }
    len = other.len;
    data = new char[len + 1];
    strcpy_s(data, len + 1, other.data);

    return *this;
  }

  string::string(string&& other)
  {
    len = other.len;
    data = other.data;
    other.len = 0;
    other.data = nullptr;
  }

  string string::operator=(string&& other)
  {
    if (data)
    {
      delete[] data;
    }
    len = other.len;
    data = other.data;
    other.len = 0;
    other.data = nullptr;

    return *this;
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
