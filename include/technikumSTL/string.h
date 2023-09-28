#pragma once

namespace technikum
{
  class string
  {
   public:
    string();
    string(const char* str);
    string(const string& other);
    string operator=(const string& other);

    string(string&& other);
    string operator=(string&& other);

    ~string();

    void append(const string& other);

    const char* c_str() const;

    int length() const;
    int size() const;

   private:
    char* data;
    int len;
  };
}  // namespace technikum
