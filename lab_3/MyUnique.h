#ifndef MYUNIQUE_H
#define MYUNIQUE_H

template<class T>
class MyUnique
{
    T * p;
public:
    MyUnique(T *p = nullptr);
    ~MyUnique();
    MyUnique(const MyUnique&) = delete;
    MyUnique& operator=(const MyUnique&) = delete;
    MyUnique(MyUnique&& other) noexcept;
    MyUnique& operator=(MyUnique&& other) noexcept;
    T * get() const;
    T & operator*();
    T * operator->();
};

template<class T>
MyUnique<T>::MyUnique(T *p) : p(p) {}

template<class T>
MyUnique<T>::~MyUnique() {
    delete p;
}

template<class T>
MyUnique<T>::MyUnique(MyUnique&& other) noexcept : p(other.p) {
    other.p = nullptr;
}

template<class T>
MyUnique<T>& MyUnique<T>::operator=(MyUnique&& other) noexcept {
    if (this != &other) {
        delete p;
        p = other.p;
        other.p = nullptr;
    }
    return *this;
}

template<class T>
T * MyUnique<T>::get() const {
    return p;
}

template<class T>
T & MyUnique<T>::operator*() {
    return *p;
}

template<class T>
T * MyUnique<T>::operator->() {
    return p;
}

#endif