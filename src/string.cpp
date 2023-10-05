#include "technikumSTL/string.h"

#include <cstring>
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
}  // namespace technikum
