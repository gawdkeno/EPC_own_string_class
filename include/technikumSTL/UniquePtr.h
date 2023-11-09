#ifndef TECHNIKUMSTL_UNIQUE_PTR_H
#define TECHNIKUMSTL_UNIQUE_PTR_H

#include <algorithm>
#include <utility>  
#include <memory>

// The Deleter is templated with a default Deleter.
template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr {
private:
    T* ptr;       
    Deleter deleter; 

public:
    explicit UniquePtr(T* p = nullptr, Deleter d = Deleter()) noexcept
        : ptr(p), deleter(d) {}

    ~UniquePtr() {
        if (ptr) {
            deleter(ptr);
        }
    }

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept
        : ptr(other.ptr), deleter(std::move(other.deleter)) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            Reset(other.Release()); // Automatically delete the current object, if any
            deleter = std::move(other.deleter);
        }
        return *this;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Member access operator
    T* operator->() const noexcept {
        return ptr;
    }

    // Boolean conversion operator
    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }

    T* Release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void Reset(T* p = nullptr) noexcept {
        T* oldPtr = ptr;
        ptr = p; // Update the pointer
        if (oldPtr) {
            deleter(oldPtr); // Delete the old object
        }
    }

    void Swap(UniquePtr& other) noexcept {
        using std::swap;
        swap(ptr, other.ptr);
        swap(deleter, other.deleter);
    }

    // Prevent copy operations
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
};

#endif // TECHNIKUMSTL_UNIQUE_PTR_H
