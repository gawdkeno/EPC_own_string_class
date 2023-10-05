#pragma once

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

   private:
    static size_t my_strlen(const char* str);
    static void my_strcpy(char* dest, size_t destSize, const char* src);
    static void my_strcat(char* dest, size_t destSize, const char* src);
    char* data;
    size_t len;
  };
}  // namespace technikum
