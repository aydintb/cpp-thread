#include <iostream>

int main() {
    int x = 5;
    double y = static_cast<double>(x);
    std::cout << "y = " << y << std::endl;

    class Base {
    public:
        virtual void foo() {}
    };

    class Derived : public Base {
    public:
        void bar() {}
    };

    Derived d;
    Base* ptr1 = &d;
    Derived* ptr2 = static_cast<Derived*>(ptr1);
    ptr2->bar();

    return 0;
}

