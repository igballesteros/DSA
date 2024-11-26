/*
Dynamic memory allocation happens during runtime - not during compile time as static memory

Allocated using the new or new[] operators -> add "new" library
Free memory using delete or delete operators -> values shall be a pointer or a memory block allocated with new

*/

#include <iostream>
#include <new>

int main() {

    int* foo; // Allocate mem to contain one single element of type int
    foo = new int[5]; // allocate mem to contain 'x' (5) elements of type int

    // foo now points to the first element of a block of memory of size 5 int

    for (int i = 0; i < 5; i++) {
        std::cin >> foo[i];
    }

    for (int i = 0; i < 5; i++) {
        std::cout << foo[i] << " address " << &foo[i] << "\n";
    }

    /*
      There are two ways of checking if the memory was allocated successfully
        1. the "new" keyword will throw an exeption erron and terminate the program automatically
        2. the "nothrow" method - returns a null pointer and the program keeps executing

      ex.
        int * foo;
        foo = new (nothrow) int [5];
        if (foo == nullptr) {
            // error assigning memory. Take measures.
        }
    */
    delete[] foo; // frees the whole memory block reserverd for the array

}
