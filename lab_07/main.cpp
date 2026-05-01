#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <mutex>
#include <string>

std::mutex mtx_cout;
std::mutex mtx_rng;
std::mt19937 rng(std::random_device{}());

void mul_thread(const std::string& name,int n,const std::vector<double>& a,const std::vector<double>& b) {
    for(int i=0;i<n; ++i) {

        std::lock_guard<std::mutex> lk(mtx_cout);
        std::cout<<name<<": ";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout<< a[i] <<" * "<< b[i] <<" = " << a[i]*b[i] << std::endl;

    }
}

void add_thread(const std::string& name,int n,const std::vector<double>& a,const std::vector<double>& b) {
    for(int i=0;i<n; ++i) {
        std::lock_guard<std::mutex> lk(mtx_cout);
        std::cout<<name<<": ";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout<< a[i] <<" + "<< b[i] <<" = " << a[i]+b[i] << std::endl;
    }
}


void rnd_thread(const std::string& name,int n) {
    std::uniform_real_distribution<double> dist(0.0,100.0);
    for(int i=0;i<n; ++i) {
        double val;
        {
            std::lock_guard<std::mutex> lk(mtx_rng);
            val= dist(rng);
        }
        std::lock_guard<std::mutex> lk(mtx_cout);
        std::cout<<name<<": ";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout<< val << std::endl;
    }
}

int main() {
    int n1=25, n2=20, n3=30;
    std::cout<<"Vvedite n1 n2 n3 (ili 0 dlya znacheniy po umolchaniyu): ";
    int in1,in2,in3;
    std::cin>> in1 >> in2 >> in3;
    if(in1>=20 && in1<=30) n1=in1;
    if(in2>=20 && in2<=30) n2=in2;
    if(in3>=20 && in3<=30) n3=in3;

    int max_n= std::max(n1,n2);
    std::vector<double> A(max_n), B(max_n);
    {
        std::lock_guard<std::mutex> lk(mtx_rng);
        std::uniform_real_distribution<double> d(0.0,100.0);
        for(int i=0;i<max_n; ++i) {
            A[i]= d(rng);
            B[i]= d(rng);
        }
    }

    std::thread t1(mul_thread, std::string("Potok1"), n1, std::cref(A), std::cref(B));
    std::thread t2(add_thread, std::string("Potok2"), n2, std::cref(A), std::cref(B));
    std::thread t3(rnd_thread, std::string("Potok3"), n3);
    t1.join();
    t2.join();
    t3.join();

    std::cout<<"Rabota zavershena."<<std::endl;
    return 0;
}