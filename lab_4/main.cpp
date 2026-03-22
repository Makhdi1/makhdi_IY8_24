#include <iostream>
using namespace std;

class point
{
    double x, y;
public:
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    virtual void print()
    {
        cout << "\nx=" << x << " y=" << y;
    }
};

class point3d : public point
{
    double z;
public:
    point3d(double x, double y, double z) : point(x, y)
    {
        this->z = z;
    }
    void print()
    {
        point::print();
        cout << " z=" << z;
    }
};

int main()
{
    point p1(1, 2);
    point3d p3(3, 4, 5);
    point *pp;
    pp = &p1;
    pp->print();
    pp = &p3;
    pp->print();
    return 0;
}