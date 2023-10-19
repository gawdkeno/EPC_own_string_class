#include "technikumSTL/UniquePtr.h"

namespace technikum
{
  template<typename T>
  class UniquePtr
  {
    UniquePtr<T>()
    {
      this.Pointer = nullptr;
    }
    ~UniquePtr()
    { 
        delete Pointer;
    }

    UniquePtr<T>(const T& other)
    {
        this.Pointer = *other;
    }

    UniquePtr<T>& operator=(const UniquePtr<T>& other)
    {
        this.Pointer = other.Pointer;
        return *this;
    }

    UniquePtr<T>(UniquePtr<T>&& other) noexcept
    {
        this.Pointer = *other;
        other.Pointer = nullptr;
    }

    UniquePtr<T>& operator=(UniquePtr<T>&& other) noexcept
    {
        this.Pointer = *other;
        other.Pointer = nullptr;
        return *this;
    }

    T& operator*()
    {
    }
    T& *operator->()
    {
        return *Pointer;
    }
    bool operator bool() const
    {
        if (this.Pointer == nullptr)
        {
          return false;
        }
        return true;
    }

    T* Release()
    {
        T* t = Pointer;
        this.Pointer = nullptr;
        return t;
    }
    void Reset()
    {
    }
    void Swap(UniquePtr<T> other)
    {
        T* t = this.Pointer;
        this.Pointer = other.Pointer;
        other.Pointer = t;
    }
  };
}  // namespace technikum