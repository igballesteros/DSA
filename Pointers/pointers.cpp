#include <iostream>

int main() {

    int x = 4;

    char A[] = "Hi universe\n";

    char h = 's';
    int* ptr = &x;
    double aa = 3.3;

    std::cout << "Hello World\n";

    std::cout << A;

    std::cout << ptr << " points to " << *ptr << " which is the address of " << x << " located in " << &x << "\n";

}