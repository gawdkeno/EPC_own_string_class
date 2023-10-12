#pragma once
#include <iterator>

namespace technikum
{
  class string
  {
   public:
    string();
    ~string();

    string(const char* str);

    string(const string& other);
    string& operator=(const string& other);
    string(string&& other) noexcept;
    string& operator=(string&& other) noexcept;
    string operator+(const string& other);
    string& operator+=(const string& other);
    string operator+(const char* other);
    string& operator+=(const char* other);

    void append(const string& other);

    const char* c_str() const;

    size_t length() const;
    size_t size() const;

    // Forward declarations of iterator classes
    class Iterator;
    class ConstIterator;

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

   private:
    static size_t my_strlen(const char* str);
    static void my_strcpy(char* dest, size_t destSize, const char* src);
    static void my_strcat(char* dest, size_t destSize, const char* src);
    char* data;
    size_t len;
  };

  class string::Iterator
  {
   public:
    Iterator(char* ptr);
    Iterator& operator++();
    Iterator operator++(int);
    char& operator*();
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

   private:
    char* current;
  };

  class string::ConstIterator
  {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = const char;
    using difference_type = std::ptrdiff_t;  // char
    using pointer = const char*;
    using reference = const char&;

    ConstIterator(const char* ptr);
    ConstIterator& operator++();
    ConstIterator operator++(int);
    const char& operator*();
    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;

   private:
    const char* current;
  };
}  // namespace technikum
