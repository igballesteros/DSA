#include <iostream>

#define MAX_SIZE 50

void Enqueue() {

}

int main() {

    int option = 0;

    std::cout << "Welcome to the queue program (array) - choose an option:\n";

    while (option < 3) {
        std::cout << "Option 1 - Add a number to the queue\n";
        std::cout << "Option 2 - Display the queue (front to end)\n";
        std::cout << "Option 3 - Remove a number from the queue\n";
        std::cout << "Option 4 - Check if queue is empty\n";
        std::cout << "Option 5 - Check front element\n";
        std::cout << "Option 6+ - Exit\n";

        std::cin >> option;

        if (option == 1) {
            // add a number to the queue
        }
        else if (option == 2) {
            // display queue
        }
        else if (option == 3) {
            // remove an element from the queue
        }
        else if (option == 4) {
            // check if queue is empty
        }
        else if (option == 5) {
            // check top element
        }

    }
}