#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <class T>
class vector
{
public:
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

    vector(size_type n, const T& value = T())
        : m_data(nullptr), m_size(0), m_capacity(0)
    {
        if (n > 0) {
            reserve(n);
            for (size_type i = 0; i < n; ++i)
                push_back(value);
        }
    }

    vector(const vector& other)
        : m_data(nullptr), m_size(0), m_capacity(0)
    {
        reserve(other.m_size);
        for (const auto& elem : other)
            push_back(elem);
    }

    ~vector()
    {
        clear();
        ::operator delete(m_data);
    }

    vector& operator=(const vector& other)
    {
        if (this != &other) {
            vector tmp(other);
            swap(tmp);
        }
        return *this;
    }

    reference operator[](size_type index) { return m_data[index]; }
    const_reference operator[](size_type index) const { return m_data[index]; }

    reference at(size_type index)
    {
        if (index >= m_size) throw std::out_of_range("at");
        return m_data[index];
    }
    const_reference at(size_type index) const
    {
        if (index >= m_size) throw std::out_of_range("at");
        return m_data[index];
    }

    reference front()
    {
        if (empty()) throw std::out_of_range("front");
        return m_data[0];
    }
    const_reference front() const
    {
        if (empty()) throw std::out_of_range("front");
        return m_data[0];
    }

    reference back()
    {
        if (empty()) throw std::out_of_range("back");
        return m_data[m_size-1];
    }
    const_reference back() const
    {
        if (empty()) throw std::out_of_range("back");
        return m_data[m_size-1];
    }

    T* data() { return m_data; }
    const T* data() const { return m_data; }

    iterator begin() { return m_data; }
    const_iterator begin() const { return m_data; }
    iterator end() { return m_data + m_size; }
    const_iterator end() const { return m_data + m_size; }

    bool empty() const { return m_size == 0; }
    size_type size() const { return m_size; }
    size_type capacity() const { return m_capacity; }

    void reserve(size_type new_cap)
    {
        if (new_cap <= m_capacity) return;
        T* new_data = static_cast<T*>(::operator new(new_cap * sizeof(T)));
        size_type i = 0;
        try {
            for (; i < m_size; ++i)
                new (new_data + i) T(m_data[i]);
        } catch (...) {
            for (size_type j = 0; j < i; ++j)
                (new_data + j)->~T();
            ::operator delete(new_data);
            throw;
        }
        for (size_type j = 0; j < m_size; ++j)
            (m_data + j)->~T();
        ::operator delete(m_data);
        m_data = new_data;
        m_capacity = new_cap;
    }

    void clear()
    {
        for (size_type i = 0; i < m_size; ++i)
            (m_data + i)->~T();
        m_size = 0;
    }

    iterator insert(iterator pos, const T& value)
    {
        size_type idx = pos - begin();
        if (idx > m_size) throw std::out_of_range("insert");
        if (pos == end()) {
            push_back(value);
            return begin() + idx;
        }
        if (m_size == m_capacity) {
            size_type new_cap = m_capacity == 0 ? 1 : m_capacity * 2;
            reserve(new_cap);
            pos = begin() + idx;
        }
        new (m_data + m_size) T(m_data[m_size-1]);
        for (size_type i = m_size-1; i > idx; --i)
            m_data[i] = m_data[i-1];
        m_data[idx] = value;
        ++m_size;
        return begin() + idx;
    }

    void push_back(const T& value)
    {
        if (m_size == m_capacity) {
            size_type new_cap = m_capacity == 0 ? 1 : m_capacity * 2;
            reserve(new_cap);
        }
        new (m_data + m_size) T(value);
        ++m_size;
    }

    void pop_back()
    {
        if (empty()) throw std::out_of_range("pop_back");
        --m_size;
        (m_data + m_size)->~T();
    }

    void swap(vector& other)
    {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
    }

private:
    T* m_data;
    size_type m_size;
    size_type m_capacity;
};

template <class T>
void swap(vector<T>& a, vector<T>& b) { a.swap(b); }

#endif