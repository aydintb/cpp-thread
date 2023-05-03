#include <iostream>

int main() {
    const int x = 5;
    const int* ptr1 = &x;

    // This won't compile because ptr1 is a const pointer.
    // *ptr1 = 6;

    // Cast away the const-ness of ptr1.
    int* ptr2 = const_cast<int*>(ptr1);

    // Modify the value through the non-const pointer.
    *ptr2 = 6;

    std::cout << "x is now " << x << std::endl;

    return 0;
}

