#pragma once

#include <iterator>
#include <cstddef>

namespace technikum
{
  class string
  {
   public:
    string();
    ~string();

    string(const char* str);
    string(const string& other);
    string(string&& other) noexcept;

    string& operator=(string other);              
    string operator+(const string& other) const;  
    string& operator+=(const string& other);
    string operator+(const char* other) const; 
    string& operator+=(const char* other);

    void append(const string& other);

    const char* c_str() const;
    size_t length() const;
    size_t size() const;

    template<typename CharType>
    class BasicIterator;

    // Typedefs for const and non-const iterators
    using Iterator = BasicIterator<char>;
    using ConstIterator = BasicIterator<const char>;

    // Begin and end functions for iterators
    Iterator begin()
    {
      return Iterator(data);
    }
    ConstIterator begin() const
    {
      return ConstIterator(data);
    }
    Iterator end()
    {
      return Iterator(data + len);
    }
    ConstIterator end() const
    {
      return ConstIterator(data + len);
    }

    // Templated iterator class
    template<typename CharType>
    class BasicIterator
    {
     public:
      using iterator_category = std::forward_iterator_tag;
      using value_type = typename std::remove_const<CharType>::type;
      using difference_type = std::ptrdiff_t;
      using pointer = CharType*;
      using reference = CharType&;

      explicit BasicIterator(pointer ptr) : m_ptr(ptr)
      {
      }

      // Dereference operator
      reference operator*() const
      {
        return *m_ptr;
      }
      // Member access operator
      pointer operator->()
      {
        return m_ptr;
      }

      // Prefix increment
      BasicIterator& operator++()
      {
        m_ptr++;
        return *this;
      }
      // Postfix increment
      BasicIterator operator++(int)
      {
        BasicIterator temp = *this;
        ++(*this);
        return temp;
      }

      // Equality comparison
      friend bool operator==(const BasicIterator& a, const BasicIterator& b)
      {
        return a.m_ptr == b.m_ptr;
      }
      // Inequality comparison
      friend bool operator!=(const BasicIterator& a, const BasicIterator& b)
      {
        return a.m_ptr != b.m_ptr;
      }

     private:
      pointer m_ptr;
    };

   private:
    static size_t my_strlen(const char* str);
    static void my_strcpy(char* dest, size_t destSize, const char* src);
    static void my_strcat(char* dest, size_t destSize, const char* src);
    void swap(string& other) noexcept;  

    char* data;
    size_t len;
  };
}  // namespace technikum