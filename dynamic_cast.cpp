#include <iostream>

class Base {
public:
    virtual void foo() {}
};

class Derived : public Base {
public:
    void bar() {}
};

int main() {
    Base* ptr1 = new Derived;
    Derived* ptr2 = dynamic_cast<Derived*>(ptr1);

    if (ptr2) {
        ptr2->bar();
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    delete ptr1;

    return 0;
}

