#pragma once

namespace technikum
{
  template<typename T>
  class UniquePtr
  {
    UniquePtr<T>();
    ~UniquePtr();

    UniquePtr<T>(const T& other);
    UniquePtr<T>& operator=(const UniquePtr<T>& other);
    UniquePtr<T>(UniquePtr<T>&& other) noexcept;
    UniquePtr<T>& operator=(UniquePtr<T>&& other) noexcept;

    T& operator*();
    T& operator->();
    bool operator bool() const;

    void Release();
    void Reset();
    void Swap(UniquePtr<T> other);

    private
    T* Pointer;
  };
}  // namespace technikum