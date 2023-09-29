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
    string operator=(const string& other);

    string(string&& other);
    string operator=(string&& other);

    size_t my_strlen(const char* str) const;
    void my_strcpy(char* dest, size_t destSize, const char* src);
    void my_strcat(char* dest, size_t destSize, const char* src);

    void append(const string& other);

    const char* c_str() const;

    size_t length() const;
    size_t size() const;

   private:
    char* data;
    size_t len;
  };
}  // namespace technikum
