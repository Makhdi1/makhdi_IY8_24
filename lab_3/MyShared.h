#ifndef MYSHARED_H
#define MYSHARED_H

template<class T>
class MyShared
{
    T * p;
    int * count;
public:
    MyShared(T *p = nullptr);
    ~MyShared();
    MyShared(const MyShared& other);
    MyShared& operator=(const MyShared& other);
    MyShared(MyShared&& other) noexcept;
    MyShared& operator=(MyShared&& other) noexcept;
    T * get() const;
    T & operator*();
    T * operator->();
    int use_count() const;
};

template<class T>
MyShared<T>::MyShared(T *p) : p(p) {
    if (p) {
        count = new int(1);
    } else {
        count = nullptr;
    }
}

template<class T>
MyShared<T>::~MyShared() {
    if (count) {
        (*count)--;
        if (*count == 0) {
            delete p;
            delete count;
        }
    }
}

template<class T>
MyShared<T>::MyShared(const MyShared& other) : p(other.p), count(other.count) {
    if (count) {
        (*count)++;
    }
}

template<class T>
MyShared<T>& MyShared<T>::operator=(const MyShared& other) {
    if (this != &other) {
        if (count) {
            (*count)--;
            if (*count == 0) {
                delete p;
                delete count;
            }
        }

        p = other.p;
        count = other.count;

        if (count) {
            (*count)++;
        }
    }
    return *this;
}

template<class T>
MyShared<T>::MyShared(MyShared&& other) noexcept : p(other.p), count(other.count) {
    other.p = nullptr;
    other.count = nullptr;
}

template<class T>
MyShared<T>& MyShared<T>::operator=(MyShared&& other) noexcept {
    if (this != &other) {
        if (count) {
            (*count)--;
            if (*count == 0) {
                delete p;
                delete count;
            }
        }

        p = other.p;
        count = other.count;

        other.p = nullptr;
        other.count = nullptr;
    }
    return *this;
}

template<class T>
T * MyShared<T>::get() const {
    return p;
}

template<class T>
T & MyShared<T>::operator*() {
    return *p;
}

template<class T>
T * MyShared<T>::operator->() {
    return p;
}

template<class T>
int MyShared<T>::use_count() const {
    if (count) {
        return *count;
    }
    return 0;
}

#endif