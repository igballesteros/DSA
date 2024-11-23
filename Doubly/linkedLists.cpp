#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};


Node* createNode() {
    Node* temp = new Node();
    temp->next = nullptr;
    temp->prev = nullptr;

    std::cin >> temp->data;

    return temp;
}

void addNodeToList(Node** head, Node* temp) {
    std::cout << "inside function\n";
    Node* temp1 = *head;

    std::cout << *head << "\n";

    if (temp1 == nullptr) {
        *head = temp1;
        std::cout << *head << "\n";
        return;
    }
    else {
        while (temp1->next != nullptr) {
            std::cout << "temp: " << temp << "\n";
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void printNodes(Node** head) {
    std::cout << "inside function\n";
    Node* temp = *head;
    int position = 1;

    std::cout << temp << "\n";

    while (temp != nullptr) {
        std::cout << "Position: " << position << " data: " << temp->data << " ad: " << temp << " prev: " << temp->prev << " next: " << temp->next << "\n";
        temp = temp->next;
        position++;
    }
}

int main() {

    Node* head = nullptr;
    Node* temp = nullptr;
    int option = 0;

    while (option < 3) {
        std::cout << "Option 1 - Create Node\n";
        std::cout << "Option 2 - Display Nodes\n";
        // std::cout << "Option 3 - Add Node at the beginning\n";
        // std::cout << "Option 4 - Add Node at nth position\n";
        // std::cout << "Option 5 - Delete Node\n";
        // std::cout << "Option 6 - Reverse List\n";
        std::cout << "Exit - option > 2\n";

        std::cin >> option;

        if (option == 1) {
            int num = 0;
            std::cout << "Enter how many nodes do you want to create: ";
            std::cin >> num;

            for (int i = 0; i < num; i++) {
                temp = createNode();
                std::cout << temp << "\n";
                addNodeToList(&head, temp);
            }
        }
        else if (option == 2) {
            printNodes(&head);
        }
    }

}