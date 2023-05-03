#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr1(new int(5));
    std::cout << "ptr1 points to " << *ptr1 << std::endl;

    {
        // This won't compile because unique_ptr cannot be copied.
        // std::unique_ptr<int> ptr2 = ptr1;
        
        // Instead, we can transfer ownership of the pointer to ptr2.
        std::unique_ptr<int> ptr2 = std::move(ptr1);
        std::cout << "ptr2 now points to " << *ptr2 << std::endl;
    }

    if (ptr1 == nullptr) {
        std::cout << "ptr1 is null because ownership was transferred to ptr2" << std::endl;
    }

    return 0;
}

