#include "technikumSTL/string.h"
#define MAX_ITERATIONS 200

namespace technikum
{
  string::string()
  {
    len = 0;
    data = nullptr;
  }

  string::string(const char* str)
  {
    if (str == nullptr)
    {
      len = 0;
      data = nullptr;
    }
    else
    {
      len = my_strlen(str);
      data = new char[len + 1];
      my_strcpy(data, len + 1, str);
    }
  }

  string::~string()
  {
    delete[] data;
  }

  string::string(const string& other)
  {
    if (other.data == nullptr)
    {
      len = 0;
      data = nullptr;
      return;
    }
    len = other.len;
    data = new char[len + 1];
    my_strcpy(data, len + 1, other.data);
  }

  string& string::operator=(const string& other)
  {
    if (data)
    {
      delete[] data;
    }
    len = other.len;
    data = new char[len + 1];
    my_strcpy(data, len + 1, other.data);

    return *this;
  }

  string::string(string&& other) noexcept
  {
    len = other.len;
    data = other.data;
    other.len = 0;
    other.data = nullptr;
  }

  string& string::operator=(string&& other) noexcept
  {
    /*if (this == &other) */
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

  string string::operator+(const string& other)
  {
    size_t newLen = len + other.len;
    char* newData = new char[newLen + 1];
    my_strcpy(newData, newLen + 1, data);
    my_strcat(newData, newLen + 1, other.data);

    return string(newData);
  }

  string& string::operator+=(const string& other)
  {
    size_t newLen = len + other.len;
    char* newData = new char[newLen + 1];
    my_strcpy(newData, newLen + 1, data);
    my_strcat(newData, newLen + 1, other.data);

    delete[] data;
    data = newData;
    len = newLen;

    return *this;
  }

  string string::operator+(const char* other)
  {
    size_t newLen = len + my_strlen(other);
    char* newData = new char[newLen + 1];
    my_strcpy(newData, newLen + 1, data);
    my_strcat(newData, newLen + 1, other);

    return string(newData);
  }

  string& string::operator+=(const char* other)
  {
    size_t newLen = len + my_strlen(other);
    char* newData = new char[newLen + 1];
    my_strcpy(newData, newLen + 1, data);
    my_strcat(newData, newLen + 1, other);

    delete[] data;
    data = newData;
    len = newLen;

    return *this;
  }

  size_t string::my_strlen(const char* str)
  {
    size_t length = 0;

    while (str[length] != '\0' && length < MAX_ITERATIONS)
    {
      length++;
    }
    if (length >= MAX_ITERATIONS)
    {
      // error handling
    }
    return length;
  }

  void string::my_strcpy(char* dest, size_t destSize, const char* src)
  {
    size_t srcLen = my_strlen(src);

    if (srcLen >= destSize)
    {
      // handle overflow error
      return;
    }

    for (size_t i = 0; i <= srcLen; i++)
    {
      dest[i] = src[i];
    }
  }

  void string::my_strcat(char* dest, size_t destSize, const char* src)
  {
    size_t destLen = my_strlen(dest);
    size_t srcLen = my_strlen(src);

    if (destLen + srcLen >= destSize)
    {
      // handle overflow error
      return;
    }

    size_t i;
    for (i = 0; i < srcLen; i++)
    {
      dest[destLen + i] = src[i];
    }
    dest[destLen + i] = '\0';
  }

  void string::append(const string& other)
  {
    size_t newLen = len + other.len;
    char* newData = new char[newLen + 1];
    my_strcpy(newData, newLen + 1, data);
    my_strcat(newData, newLen + 1, other.data);

    delete[] data;
    data = newData;
    len = newLen;
  }

  const char* string::c_str() const
  {
    return data;
  }

  size_t string::length() const
  {
    return len;
  }

  size_t string::size() const
  {
    return len;
  }

  string::Iterator::Iterator(char* ptr) : current(ptr)
  {
  }

  string::Iterator& string::Iterator::operator++()
  {
    ++current;
    return *this;
  }

  string::Iterator string::Iterator::operator++(int)
  {
    Iterator temp = *this;
    ++current;
    return temp;
  }

  char& string::Iterator::operator*()
  {
    return *current;
  }

  bool string::Iterator::operator==(const Iterator& other) const
  {
    return current == other.current;
  }

  bool string::Iterator::operator!=(const Iterator& other) const
  {
    return current != other.current;
  }

  string::ConstIterator::ConstIterator(const char* ptr) : current(ptr)
  {
  }

  string::ConstIterator& string::ConstIterator::operator++()
  {
    ++current;
    return *this;
  }

  string::ConstIterator string::ConstIterator::operator++(int)
  {
    ConstIterator temp = *this;
    ++current;
    return temp;
  }

  const char& string::ConstIterator::operator*()
  {
    return *current;
  }

  bool string::ConstIterator::operator==(const ConstIterator& other) const
  {
    return current == other.current;
  }

  bool string::ConstIterator::operator!=(const ConstIterator& other) const
  {
    return current != other.current;
  }

  string::Iterator string::begin()
  {
    return Iterator(data);
  }

  string::Iterator string::end()
  {
    return Iterator(data + len);
  }

  string::ConstIterator string::begin() const
  {
    return ConstIterator(data);
  }

  string::ConstIterator string::end() const
  {
    return ConstIterator(data + len);
  }
}  // namespace technikum