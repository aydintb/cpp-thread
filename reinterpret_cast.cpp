#include <iostream>

int main() {
    int x = 5;
    int* ptr1 = &x;
    std::cout << "ptr1 points to " << *ptr1 << std::endl;

    // Cast ptr1 to a char pointer.
    char* ptr2 = reinterpret_cast<char*>(ptr1);
    std::cout << "ptr2 points to the same memory as ptr1, but with a different type" << std::endl;

    // Modify the memory through the char pointer.
    ptr2[0] = 'a';
    ptr2[1] = 'b';
    ptr2[2] = 'c';

    std::cout << "x is now " << x << std::endl;

    return 0;
}


