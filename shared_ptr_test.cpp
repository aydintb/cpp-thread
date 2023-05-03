#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1(new int(5));
    std::cout << "ptr1 points to " << *ptr1 << std::endl;

    {
        std::shared_ptr<int> ptr2 = ptr1;
        std::cout << "ptr1 and ptr2 both point to " << *ptr1 << std::endl;
    }

    std::cout << "ptr1 still points to " << *ptr1 << std::endl;

    ptr1.reset();

    if (ptr1 == nullptr) {
        std::cout << "ptr1 has been reset and is now null" << std::endl;
    }

    return 0;
}

// su sekilde release version compile edilebilir:
// g++ -o shared_ptr_test_release shared_ptr_test.cpp

/*

g++ -o shared_ptr_test_release shared_ptr_test.cpp

./shared_ptr_test_release 
ptr1 points to 5
ptr1 and ptr2 both point to 5
ptr1 still points to 5
ptr1 has been reset and is now null


In this example, ptr1 is a shared_ptr that points to a dynamically allocated int with a value of 5. 
When ptr2 is created and initialized with ptr1, the reference count is incremented to 2. 
When ptr2 goes out of scope and is destroyed, the reference count is decremented to 1.
When ptr1 is reset, the reference count goes to 0 and the int object is deleted. 
Finally, the program checks if ptr1 is null, which it is because it has been reset.


*/

