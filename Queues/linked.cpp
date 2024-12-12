#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node createNode() {}

void addNode(Node** head, Node* temp) {}

void displayQueue(Node* head) {}

void removeNode(Node** head) {}

bool isEmpty(Node** head) {}

void topElement(Node** head) {}

int main() {

    int option = 0;

    std::cout << "Welcome to the queue program (linked lists) - choose an option:\n";

    while (option < 6) {
        std::cout << "Option 1 - Add a number to the queue\n";
        std::cout << "Option 2 - Display the queue (beginning to end)\n";
        std::cout << "Option 3 - Remove a number from the queue\n";
        std::cout << "Option 4 - Check if queue is empty\n";
        std::cout << "Option 5 - Check front element\n";
        std::cout << "Option 6+ - Exit\n";

        std::cin >> option;
    }
}