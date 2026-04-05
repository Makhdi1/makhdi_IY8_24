#include <iostream>
using namespace std;

class Square
{
protected:
    double side;

public:
    Square(double s) : side(s) {}

    virtual double calc() const
    {
        return side * side;
    }

    void print() const
    {
        cout << "Сторона квадрата: " << side << endl;
        cout << "Площадь квадрата: " << calc() << endl;
    }
};

class Cube : public Square
{
public:
    Cube(double s) : Square(s) {}

    virtual double calc() const override
    {
        double baseArea = Square::calc();
        return side * baseArea;
    }

    void print() const
    {
        cout << "Ребро куба: " << side << endl;
        cout << "Объём куба: " << calc() << endl;
    }
};

int main()
{
    Square sq(3);
    Cube cb(3);

    cout << "=== Прямой вызов методов для объектов ===" << endl;
    sq.print();
    cout << endl;
    cb.print();

    cout << "\n=== Демонстрация динамического полиморфизма ===" << endl;
    Square* ptr;
    ptr = &sq;
    ptr->print();

    ptr = &cb;
    ptr->print();

    cout << "\n=== Демонстрация статического полиморфизма ===" << endl;

    class SquareStatic
    {
    protected:
        double side;
    public:
        SquareStatic(double s) : side(s) {}
        double calc() const { return side * side; }
        void print() const { cout << "Площадь: " << calc() << endl; }
    };

    class CubeStatic : public SquareStatic
    {
    public:
        CubeStatic(double s) : SquareStatic(s) {}
        double calc() const { return side * side * side; }
        void print() const { cout << "Объём: " << calc() << endl; }
    };

    SquareStatic* p;
    SquareStatic sqs(3);
    CubeStatic cbs(3);

    p = &sqs;
    p->print();

    p = &cbs;
    p->print();

    cout << "\nНажмите Enter для выхода...";
    cin.get();
    return 0;
}