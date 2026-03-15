#include <iostream>
#include "MyUnique.h"
#include "MyShared.h"


class Test {
public:
    int value;

    Test(int v) : value(v) {
        std::cout<< " Test( " <<v <<" )\n";
    }

    ~Test() {
        std::cout<< " ~Test( " << value << " )\n";
    }

    void print() const {
        std::cout<< " Test::print, value=" << value << "\n";
    }
};


int main() {
    std::cout<< "  MyUnique demonstration: \n";
    {
        MyUnique<Test> ptr1(new Test(10));


        (*ptr1).print();

        ptr1->print();

        Test* raw =ptr1.get();

        raw->print();

        MyUnique<Test> ptr2 = std::move(ptr1);
        if (ptr1.get()==nullptr) {
            std::cout << " ptr1 is  now null\n";

        }
        ptr2->print();


        MyUnique<Test> ptr3(new Test(20));
        ptr3=std::move(ptr2);
        if (ptr2.get()==nullptr) {
            std::cout<<" ptr2 is now null \n";
        }
        ptr3->print();
    }

    std::cout << "\n  MyShared demonstration \n";
    {

        MyShared<Test> ptr1(new Test(30));

        (*ptr1).print();

        ptr1->print();

        Test* raw =ptr1.get();
        raw->print();


        std::cout <<"use_count ptr1: " << ptr1.use_count() << "\n";

        MyShared<Test> ptr2(ptr1);
        std::cout <<"use_count  ptr1: " << ptr1.use_count() << "\n";
        std::cout<<" use_count ptr2: " << ptr2.use_count()<<  "\n";

        MyShared<Test> ptr3;
        ptr3 =ptr2;
        std::cout << " use_count ptr1: " << ptr1.use_count() << "\n";
        std::cout <<"use_count  ptr2: " << ptr2.use_count()<< "\n";
        std::cout<< "use_count  ptr3: " <<ptr3.use_count()<< "\n";

        ptr3->print();

        MyShared<Test> ptr4=std::move(ptr3);
        std::cout<< " after move: \n";
        std::cout<<" use_count ptr1:  "<<ptr1.use_count() << " \n";
        std::cout<<"use_count ptr2: "<< ptr2.use_count() <<"\n";
        std::cout <<"use_count ptr3: "<<ptr3.use_count() << "\n";
        std::cout<< "use_count ptr4: "<< ptr4.use_count() << "\n";

        if (ptr3.get()== nullptr) {
            std::cout<<"ptr3 is now null\n";
        }

        ptr4->print();

    }

    return 0;
}