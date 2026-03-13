#include <iostream>
#include <algorithm>
#include "vector.h"



struct Counted {
    static int alive;
    int x;
    Counted(int v=0) : x(v) { ++alive; }
    Counted(const Counted& o) : x(o.x) { ++alive; }
    ~Counted() { --alive; }
};
int Counted::alive = 0;
void test1() {
    std::cout << "test1 - push_back и []\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if (v.size() == 3) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v[0] == 1) std::cout <<"ok\n";else std::cout << "fail\n";
    if (v[1] == 2) std::cout<< "ok\n";else std::cout<< "fail\n";
    if (v[2] == 3) std::cout<< "ok\n"; else std::cout<< "fail\n";
}

void test2() {
    std::cout << "test2 - pop_back\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();

    if (v.size() == 1) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v[0] == 1) std::cout << "ok\n"; else std::cout << "fail\n";
}

void test3() {
    std::cout << "test3 - at и исключения\n";
    vector<int> v;
    v.push_back(5);

    try {
        v.at(0) = 10;
        if (v[0] == 10) std::cout << "ok\n"; else std::cout << "fail\n";
    } catch(...) {
        std::cout << "fail\n";
    }

    try {
        v.at(5) = 1;
        std::cout << "fail\n";
    } catch(std::out_of_range&) {
        std::cout << "ok\n";
    } catch(...) {
        std::cout << "fail\n";
    }
}

void test4() {
    std::cout << "test4 - front и back\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    if (v.front() == 1) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v.back() == 3) std::cout << "ok\n"; else std::cout << "fail\n";
}

void test5() {
    std::cout << "test5 - конструктор сразмером\n";
    vector<int> v(5, 7);

    if (v.size() == 5) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v[0] == 7 && v[4] == 7) std::cout << "ok\n"; else std::cout << "fail\n";
}

void test6() {
    std::cout << "test6 копирование\n";
    vector<int> a(3, 1);
    vector<int> b = a;

    b[0] = 5;
    if (a[0] == 1 && b[0] == 5) std::cout << "ok\n"; else std::cout << "fail\n";
    a = b;
    if (a[0] == 5) std::cout << "ok\n"; else std::cout << "fail\n";
}
void test7() {
    std::cout << "test7 - reserve\n";
    vector<int> v;
    v.reserve(10);
    if (v.capacity() == 10) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v.size() == 0) std::cout << "ok\n"; else std::cout << "fail\n";
    for (int i = 0; i < 10; i++) v.push_back(i);
    if (v.size() == 10) std::cout << "ok\n";else std::cout << "fail\n";
    if (v.capacity() == 10) std::cout <<"ok\n"; else std::cout <<"fail\n";
}

void test8() {
    std::cout <<"test8 - clear\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.clear();
    if (v.empty()) std::cout << "ok\n"; else std::cout << "fail\n";
    if (v.size() == 0) std::cout << "ok\n"; else std::cout << "fail\n";
}
void test9() {
    std::cout << "test9 - insert\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insert(v.begin() + 1, 2);
    if (v[0] == 1 && v[1] == 2 && v[2] == 3) std::cout << "ok\n";else std::cout << "fail\n";
    v.insert(v.begin(), 0);
    if (v[0] == 0) std::cout << "ok\n"; else std::cout << "fail\n";
}
void test10() {
    std::cout << "test10 - алгоритмы STL\n";
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    std::sort(v.begin(), v.end());
    if (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4) std::cout << "ok\n";else std::cout << "fail\n";
    auto it = std::find(v.begin(), v.end(), 3);
    if (*it == 3) std::cout << "ok\n"; else std::cout << "fail\n";
}
void test11() {
    std::cout << "test11 - память\n";
    std::cout << "живых Counted: " << Counted::alive << "\n";
    {
        vector<Counted> v;
        v.push_back(Counted(1));
        v.push_back(Counted(2));
        std::cout << "после push_back: " << Counted::alive << " (должно быть 2)\n";
        vector<Counted> v2 = v;
        std::cout << "после копирования: " << Counted::alive << " (должно быть 4)\n";
        v2.pop_back();
        std::cout << "после pop_back: " << Counted::alive << " (должно быть 3)\n";
    }
    std::cout << "после выхода из блока: " << Counted::alive << " (должно быть 0)\n";
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    
    test6();
    test7();
    test8();
    test9();
    
    test10();
    test11();
    std::cout << "\nвсcе тесты готовы\n";
    
    return 0;
}
